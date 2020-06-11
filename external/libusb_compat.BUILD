
# We'll use bazel rules to set up defines, so an empty file is fine.
genrule(
    name="empty_config_header",
    outs = ["libusb/config.h"],
    cmd = "echo > $@"
)

cc_library(
    name = "usb",
    deps = [
        "@com_github_libusb_libusb//:libusb",
    ],
    srcs = [
        ":empty_config_header",
        "libusb/core.c",
        "libusb/usbi.h",
    ],
    hdrs = [
        "libusb/usb.h",
    ],
    copts = [
        "-Iexternal/com_github_libusb_libusb_compat_0_1/libusb",
        "-Wno-unused-function",
        "-Wno-pointer-sign",
        "-Wno-deprecated-declarations",
    ],
    local_defines = [
        "API_EXPORTED=\"__attribute__((visibility(\\\"default\\\")))\"",
        "ENABLE_LOGGING",
    ],
    strip_include_prefix = "libusb/",
    visibility = ["//visibility:public"],
)
