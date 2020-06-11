load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "com_github_networkupstools_nut",
    build_file = "@//external:nut.BUILD",
    sha256 = "9e432a3717c6bdbd9370ee2364ac1fb43827e71e303cde224ab8b60ea22a86fa",
    strip_prefix = "nut-fab323320d5b955ed034b2eea390a9bbb549e8e5",
    urls = ["https://github.com/kleinpa/nut/archive/fab323320d5b955ed034b2eea390a9bbb549e8e5.tar.gz"],
)

http_archive(
    name = "com_github_jupp0r_prometheus_cpp",
    sha256 = "85ad6fea0f0dcb413104366b7d6109acdb015aff8767945511c5cad8202a28a6",
    strip_prefix = "prometheus-cpp-0.9.0/",
    urls = ["https://github.com/jupp0r/prometheus-cpp/archive/v0.9.0.tar.gz"],
)

load("@com_github_jupp0r_prometheus_cpp//bazel:repositories.bzl", "prometheus_cpp_repositories")

prometheus_cpp_repositories()

http_archive(
    name = "absl",
    sha256 = "8100085dada279bf3ee00cd064d43b5f55e5d913be0dfe2906f06f8f28d5b37e",
    strip_prefix = "abseil-cpp-20190808",
    urls = [
        "https://github.com/abseil/abseil-cpp/archive/20190808.tar.gz",
    ],
)

http_archive(
    name = "io_bazel_rules_docker",
    sha256 = "59536e6ae64359b716ba9c46c39183403b01eabfbd57578e84398b4829ca499a",
    strip_prefix = "rules_docker-0.22.0",
    urls = ["https://github.com/bazelbuild/rules_docker/releases/download/v0.22.0/rules_docker-v0.22.0.tar.gz"],
)

load(
    "@io_bazel_rules_docker//repositories:repositories.bzl",
    container_repositories = "repositories",
)

container_repositories()

load(
    "@io_bazel_rules_docker//cc:image.bzl",
    _cc_image_repos = "repositories",
)

_cc_image_repos()

load(
    "@io_bazel_rules_docker//repositories:go_repositories.bzl",
    container_go_deps = "go_deps",
)

container_go_deps()

load(
    "@io_bazel_rules_docker//container:container.bzl",
    "container_pull",
)

container_pull(
    name = "ubuntu",
    digest = "6701deddfa3bdabb3a50eb0a24175367b9c7b145e8b2f889ee3b2c52a295ec0a",
    registry = "index.docker.io",
    repository = "library/ubuntu",
    tag = "14.04",
)

http_archive(
    name = "com_github_libusb_libusb_compat_0_1",
    build_file = "@//external:libusb_compat.BUILD",
    sha256 = "521ac95b5bf6201b151db834d0672d56dee603f234d831822637849a81a6ae3a",
    strip_prefix = "libusb-compat-0.1-0.1.7",
    urls = ["https://github.com/libusb/libusb-compat-0.1/archive/v0.1.7.zip"],
)

# http_archive(
#     name = "com_github_libusb_libusb",
#     sha256 = "02620708c4eea7e736240a623b0b156650c39bfa93a14bcfa5f3e05270313eba",
#     urls = ["https://github.com/libusb/libusb/archive/v1.0.23.tar.gz"],
#     strip_prefix = "libusb-1.0.23",
#     build_file = "@//external:libusb.BUILD",
# )

http_archive(
    name = "com_github_libusb_libusb",
    build_file = "@//external:libusb.BUILD",
    sha256 = "a389fac698629a3e6e3222e30d4e268bfb912050e7bcbd6a25fae945e2ec1a40",
    strip_prefix = "libusb-bb3773090883409865a40e97a8cabb531fa00683",
    urls = ["https://github.com/libusb/libusb/archive/bb3773090883409865a40e97a8cabb531fa00683.tar.gz"],
)

http_archive(
    name = "rules_pkg",
    sha256 = "352c090cc3d3f9a6b4e676cf42a6047c16824959b438895a76c2989c6d7c246a",
    url = "https://github.com/bazelbuild/rules_pkg/releases/download/0.2.5/rules_pkg-0.2.5.tar.gz",
)

load("@rules_pkg//:deps.bzl", "rules_pkg_dependencies")

rules_pkg_dependencies()
