genrule(
    name="empty_config_header",
    outs = ["libusb/config.h"],
    cmd = "echo > $@"
)

cc_library(
    name = "config",
    hdrs = [
        ":empty_config_header",
    ],
    strip_include_prefix = "libusb/",
)

cc_library(
    name = "libusb",
    deps = [
        ":config",
    ],
    srcs = [
        #        ":empty_config_header",
        "libusb/core.c",
        "libusb/descriptor.c",
        "libusb/hotplug.c",
        "libusb/hotplug.h",
        "libusb/io.c",
        "libusb/libusbi.h",
        "libusb/os/linux_netlink.c",
        "libusb/os/linux_usbfs.c",
        "libusb/os/linux_usbfs.h",
        "libusb/os/poll_posix.c",
        "libusb/os/poll_posix.h",
        "libusb/os/threads_posix.c",
        "libusb/os/threads_posix.h",
        "libusb/strerror.c",
        "libusb/sync.c",
        "libusb/version.h",
        "libusb/version_nano.h",
    ],
    copts = [
        "-Iexternal/com_github_libusb_libusb/libusb",
    ],
    hdrs = [
        "libusb/libusb.h",
    ],
    local_defines=[
        "DEFAULT_VISIBILITY=\"__attribute__((visibility(\\\"default\\\")))\"",

        "ENABLE_LOGGING=1",
        "HAVE_ASM_TYPES_H=1",
        "HAVE_CLOCK_GETTIME=1",
        "HAVE_DECL_TFD_CLOEXEC=1",
        "HAVE_DECL_TFD_NONBLOCK=1",
        "HAVE_DLFCN_H=1",
        "HAVE_INTTYPES_H=1",
        "HAVE_MEMORY_H=1",
        "HAVE_NFDS_T=1",
        "HAVE_PIPE2=1",
        "HAVE_PTHREAD_SETNAME_NP=1",
        "HAVE_STDINT_H=1",
        "HAVE_STDLIB_H=1",
        "HAVE_STRINGS_H=1",
        "HAVE_STRING_H=1",
        "HAVE_SYS_STAT_H=1",
        "HAVE_SYS_TIME_H=1",
        "HAVE_SYS_TYPES_H=1",
        "HAVE_TIMERFD=1",
        "HAVE_UNISTD_H=1",

        "LT_OBJDIR=\".libs/\"",
        "PACKAGE=\"libusb-1.0\"",
        "PACKAGE_BUGREPORT=\"libusb-devel@lists.sourceforge.net\"",
        "PACKAGE_NAME=\"libusb-1.0\"",

        "PACKAGE_STRING=\"libusb-1.0 1.0.23\"",
        "PACKAGE_TARNAME=\"libusb-1.0\"",
        "PACKAGE_URL=\"http://libusb.info\"",

        "PACKAGE_VERSION=\"1.0.23\"",
        "POLL_POSIX=1",
        "STDC_HEADERS=1",

        "THREADS_POSIX=1",
        "VERSION=\"1.0.23\"",
        "_GNU_SOURCE=1",
    ],
    strip_include_prefix = "libusb/",
    visibility = ["//visibility:public"],
    linkopts = ["-pthread"],
)
