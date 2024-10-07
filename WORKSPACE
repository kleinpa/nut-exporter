load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "com_github_networkupstools_nut",
    build_file = "@//external:nut.BUILD",
    sha256 = "7ff55e6426077f3b234afc56fecac3bf83cd56eccef85aab0163cd6298a5a15f",
    strip_prefix = "nut-fd6f4188b791af9c5817cfa678e23f317b146df2",
    urls = ["https://github.com/networkupstools/nut/archive/fd6f4188b791af9c5817cfa678e23f317b146df2.tar.gz"],
)

http_archive(
    name = "com_github_libusb_libusb",
    build_file = "@//external:libusb.BUILD",
    integrity = "sha256-RZy88lN+aYBpSBVNdEYUrxzQZoqNjBoFOOW2i2+4W9c=",
    strip_prefix = "libusb-cc498ded18fb2c6e4506c546d0351c4ae91ef2cc",
    urls = ["https://github.com/libusb/libusb/archive/cc498ded18fb2c6e4506c546d0351c4ae91ef2cc.tar.gz"],
)
