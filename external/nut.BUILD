package(default_visibility = ["//visibility:public"])

cc_library(
    name = "nutclient",
    srcs = ["clients/nutclient.cpp"],
    hdrs = ["clients/nutclient.h"],
    strip_include_prefix = "clients/",
)

genrule(name="version_header",
        outs = ["include/nut_version.h"],
        cmd = "echo > $@",
)

# We'll use bazel rules to set up defines, so an empty file is fine.
genrule(name="empty_config_header",
        outs = ["include/config.h"],
        cmd = "echo > $@",
)

cc_library(
    name = "common",
    srcs = [
        "common/common.c",
        "common/state.c",
        "common/str.c",
        "common/upsconf.c",
        "common/parseconf.c",
    ],
    hdrs = [
        ":empty_config_header",
        ":version_header",
        "include/attribute.h",
        "include/common.h",
        "include/extstate.h",
        "include/nut_stdint.h",
        "include/parseconf.h",
        "include/proto.h",
        "include/state.h",
        "include/str.h",
        "include/timehead.h",
        "include/upsconf.h",
    ],
    defines = [
        "HAVE_STDARG_H",
        "HAVE_SETENV",
        "HAVE_STDINT_H",
    ],
    local_defines = [

        "NUT_VERSION_MACRO=\"\\\"TODO: version\\\"\"",

        "LIBDIR=\\\"/usr/local/ups/lib\\\"",
        "LOG_FACILITY=LOG_DAEMON",
        "HAVE_SETEUID",
        "PIDPATH=\\\"/var/run\\\"",
        "CONFPATH=\\\"/usr/local/ups/etc\\\"",
        "STATEPATH=\\\"/var/state/ups\\\"",
    ],
    strip_include_prefix = "include/",
)

cc_binary(
    name = "upsd",
    deps = [":common"],
    defines = [
        "NUT_NETVERSION=\\\"1.2\\\"",
    ],
    local_defines = [
        "RUN_AS_USER=\\\"nobody\\\"",
        "RUN_AS_GROUP=\\\"nobody\\\"",
        "DATADIR=\\\"/usr/local/ups/share\\\"",
    ],
    srcs = [
        "server/conf.c",
        "server/conf.h",
        "server/desc.c",
        "server/desc.h",
        "server/netcmds.h",
        "server/neterr.h",
        "server/netget.c",
        "server/netget.h",
        "server/netinstcmd.c",
        "server/netinstcmd.h",
        "server/netlist.c",
        "server/netlist.h",
        "server/netmisc.c",
        "server/netmisc.h",
        "server/netset.c",
        "server/netset.h",
        "server/netssl.c",
        "server/netssl.h",
        "server/netuser.c",
        "server/netuser.h",
        "server/nut_ctype.h",
        "server/sstate.c",
        "server/sstate.h",
        "server/stype.h",
        "server/upsd.c",
        "server/upsd.h",
        "server/upstype.h",
        "server/user-data.h",
        "server/user.c",
        "server/user.h",
    ],
)

cc_binary(
    name = "usbhid-ups",
    deps = [
        ":common",
        "@com_github_libusb_libusb_compat_0_1//:usb",
    ],
    local_defines = [
        "HAVE_USB",
        "RUN_AS_USER=\\\"nobody\\\"",
        "RUN_AS_GROUP=\\\"nobody\\\"",
        # "DATADIR=\\\"/usr/local/ups/share\\\"",
    ],
    srcs = [
        "drivers/apc-hid.c",
        "drivers/apc-hid.h",
        "drivers/belkin-hid.c",
        "drivers/belkin-hid.h",
        "drivers/cps-hid.c",
        "drivers/cps-hid.h",
        "drivers/dstate.c",
        "drivers/dstate.h",
        "drivers/explore-hid.c",
        "drivers/explore-hid.h",
        "drivers/hidparser.c",
        "drivers/hidparser.h",
        "drivers/hidtypes.h",
        "drivers/idowell-hid.c",
        "drivers/idowell-hid.h",
        "drivers/libhid.c",
        "drivers/libhid.h",
        "drivers/libusb.c",
        "drivers/libusb.h",
        "drivers/liebert-hid.c",
        "drivers/liebert-hid.h",
        "drivers/main.c",
        "drivers/main.h",
        "drivers/mge-hid.c",
        "drivers/mge-hid.h",
        "drivers/openups-hid.c",
        "drivers/openups-hid.h",
        "drivers/powercom-hid.c",
        "drivers/powercom-hid.h",
        "drivers/tripplite-hid.c",
        "drivers/tripplite-hid.h",
        "drivers/upshandler.h",
        "drivers/usb-common.c",
        "drivers/usb-common.h",
        "drivers/usbhid-ups.c",
        "drivers/usbhid-ups.h",
    ],
    linkopts = ["-pthread"],
)
