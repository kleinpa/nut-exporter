load("@io_bazel_rules_docker//container:container.bzl", "container_image")

cc_binary(
    name = "nut_exporter",
    srcs = ["main.cc"],
    visibility = ["//visibility:public"],
    deps = [
        "@com_github_jupp0r_prometheus_cpp//pull",
        "@com_github_networkupstools_nut//:nutclient",
        "@com_google_absl//absl/flags:flag",
        "@com_google_absl//absl/flags:parse",
        "@com_google_absl//absl/strings:str_format",
    ],
)

container_image(
    name = "nut_exporter_image",
    base = "@distroless_cc_base//image",
    files = [
        ":nut_exporter",
        "@com_github_networkupstools_nut//:upsd",
        "@com_github_networkupstools_nut//:usbhid-ups",
    ],
)
