load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "com_github_networkupstools_nut",
    build_file = "@//external:nut.BUILD",
    sha256 = "2f1ed256a6b3fcac27e8e1e4f47fbf14d20431504d454fb5a6cac9d257e9feee",
    strip_prefix = "nut-e01e8912eff2c27fb30c27019ed7eba131b13aec",
    urls = ["https://github.com/networkupstools/nut/archive/e01e8912eff2c27fb30c27019ed7eba131b13aec.tar.gz"],
)

http_archive(
    name = "com_github_libusb_libusb",
    build_file = "@//external:libusb.BUILD",
    sha256 = "",
    strip_prefix = "libusb-cc498ded18fb2c6e4506c546d0351c4ae91ef2cc",
    urls = ["https://github.com/libusb/libusb/archive/cc498ded18fb2c6e4506c546d0351c4ae91ef2cc.tar.gz"],
)

http_archive(
    name = "com_github_jupp0r_prometheus_cpp",
    sha256 = "",
    strip_prefix = "prometheus-cpp-4b03769662cfdbfa2f31c21bb162cf495aa2a607",
    urls = ["https://github.com/jupp0r/prometheus-cpp/archive/4b03769662cfdbfa2f31c21bb162cf495aa2a607.zip"],
)

load("@com_github_jupp0r_prometheus_cpp//bazel:repositories.bzl", "prometheus_cpp_repositories")

prometheus_cpp_repositories()

http_archive(
    name = "com_google_absl",
    sha256 = "6f03495ec2fdc582b2e858e04a268caf2415c12633f7634a3b99c1698950f05f",
    strip_prefix = "abseil-cpp-03b8d6ea3dc6a0b8c6bcf42503c2053754dab2e4",
    urls = ["https://github.com/abseil/abseil-cpp/archive/03b8d6ea3dc6a0b8c6bcf42503c2053754dab2e4.zip"],
)

http_archive(
    name = "io_bazel_rules_docker",
    sha256 = "",
    strip_prefix = "rules_docker-8e70c6bcb584a15a8fd061ea489b933c0ff344ca",
    urls = ["https://github.com/bazelbuild/rules_docker/archive/8e70c6bcb584a15a8fd061ea489b933c0ff344ca.zip"],
)

load(
    "@io_bazel_rules_docker//repositories:repositories.bzl",
    container_repositories = "repositories",
)

container_repositories()

load("@io_bazel_rules_docker//repositories:deps.bzl", container_deps = "deps")

container_deps()

load(
    "@io_bazel_rules_docker//container:container.bzl",
    "container_pull",
)

container_pull(
    name = "distroless_cc_base",
    digest = "sha256:41036fc7ed8df0f6addc18484cef0c94a85867508967789f947e11ffd5ff0cc8",
    registry = "gcr.io",
    repository = "distroless/cc",
)
