load("@build_bazel_rules_apple//apple:macos.bzl", "macos_application", "macos_command_line_application")

objc_library(
    name = "libmain",
    srcs = ["main.cc"],
    data = [
        "test.txt",
    ],
    deps = [
        "@bazel_tools//tools/cpp/runfiles",
    ],
)

macos_command_line_application(
    name = "main",
    bundle_id = "orion.warriorstar.main",
    infoplists = [":Info.plist"],
    minimum_os_version = "10.15",
    deps = [
        ":libmain",
    ],
)
