#include <prometheus/counter.h>
#include <prometheus/exposer.h>
#include <prometheus/registry.h>

#include <chrono>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <mutex>
#include <string>
#include <thread>

#include "absl/flags/flag.h"
#include "absl/flags/parse.h"
#include "absl/strings/str_format.h"
#include "nutclient.h"

ABSL_FLAG(std::string, listen_address, "0.0.0.0:8080",
          "prometheus client listen address");
ABSL_FLAG(std::string, prometheus_namespace, "ups",
          "prometheus client listen address");

// TODO: use query params?
ABSL_FLAG(std::string, nut_host, "127.0.0.1", "");
ABSL_FLAG(uint16_t, nut_port, 3493, "");
ABSL_FLAG(std::string, nut_device, "upsname", "");

prometheus::MetricFamily makeGauge(std::string name, double value) {
  prometheus::MetricFamily family;
  family.name =
      absl::StrFormat("%s_%s", absl::GetFlag(FLAGS_prometheus_namespace), name);
  family.type = prometheus::MetricType::Gauge;
  prometheus::ClientMetric metric;
  metric.gauge.value = value;
  family.metric.push_back(metric);
  return family;
}

class CallbackCollectable : public prometheus::Collectable {
 public:
  CallbackCollectable(std::function<std::vector<prometheus::MetricFamily>()> fn)
      : fn_(fn) {}
  std::vector<prometheus::MetricFamily> Collect() const { return fn_(); }

 private:
  std::function<std::vector<prometheus::MetricFamily>()> fn_;
};

int main(int argc, char** argv) {
  absl::ParseCommandLine(argc, argv);

  std::cout << "starting";

  // Ensure that only one client is active at a time
  std::mutex client_mutex;

  auto exp = std::make_shared<CallbackCollectable>([&client_mutex]() {
    const std::lock_guard<std::mutex> lock(client_mutex);

    nut::TcpClient nut_client;
    nut_client.connect(absl::GetFlag(FLAGS_nut_host),
                       absl::GetFlag(FLAGS_nut_port));
    auto value_map = nut_client.getDevice(absl::GetFlag(FLAGS_nut_device))
                         .getVariableValues();
    auto results = std::vector<prometheus::MetricFamily>{};

    if (value_map.count("battery.charge") > 0 &&
        value_map.at("battery.charge").size() > 0) {
      try {
        results.push_back(
            makeGauge("battery_charge_ratio",
                      std::stod(value_map.at("battery.charge")[0]) / 100));
      } catch (std::invalid_argument) {
      }
    }

    if (value_map.count("battery.runtime") > 0 &&
        value_map.at("battery.runtime").size() > 0) {
      try {
        results.push_back(
            makeGauge("battery_runtime_seconds",
                      std::stod(value_map.at("battery.runtime")[0])));
      } catch (std::invalid_argument) {
      }
    }

    if (value_map.count("battery.voltage") > 0 &&
        value_map.at("battery.voltage").size() > 0) {
      try {
        results.push_back(makeGauge(
            "battery_volts", std::stod(value_map.at("battery.voltage")[0])));
      } catch (std::invalid_argument) {
      }
    }

    if (value_map.count("input.voltage") > 0 &&
        value_map.at("input.voltage").size() > 0) {
      try {
        results.push_back(makeGauge(
            "input_volts", std::stod(value_map.at("input.voltage")[0])));
      } catch (std::invalid_argument) {
      }
    }

    if (value_map.count("output.voltage") > 0 &&
        value_map.at("output.voltage").size() > 0) {
      try {
        results.push_back(makeGauge(
            "output_volts", std::stod(value_map.at("output.voltage")[0])));
      } catch (std::invalid_argument) {
      }
    }

    if (value_map.count("ups.load") > 0 &&
        value_map.at("ups.load").size() > 0) {
      try {
        results.push_back(makeGauge(
            "load_ratio", std::stod(value_map.at("ups.load")[0]) / 100));
      } catch (std::invalid_argument) {
      }
    }

    if (value_map.count("ups.realpower.nominal") > 0 &&
        value_map.at("ups.realpower.nominal").size() > 0) {
      try {
        results.push_back(
            makeGauge("nominal_watts",
                      std::stod(value_map.at("ups.realpower.nominal")[0])));
      } catch (std::invalid_argument) {
      }
    }

    return results;
  });

  prometheus::Exposer exposer{absl::GetFlag(FLAGS_listen_address)};
  exposer.RegisterCollectable(exp);

  std::cout << "ready";

  // Sleep forever
  std::this_thread::sleep_until(
      std::chrono::system_clock::now() +
      std::chrono::hours(std::numeric_limits<int>::max()));
}
