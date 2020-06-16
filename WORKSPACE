workspace(name = "bugs_macos_cliapp_runfiles")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

http_archive(
    name = "com_grail_bazel_toolchain",
    sha256 = "7b61414f83c0ace2f5af259ee780360019b565b921f531070b848469f42701e4",
    strip_prefix = "bazel-toolchain-0.5.3",
    urls = ["https://github.com/grailbio/bazel-toolchain/archive/0.5.3.tar.gz"],
)

git_repository(
    name = "build_bazel_rules_apple",
    commit = "5b90a07058a449d2f3207245c0cad1310c8c3681",
    remote = "https://github.com/bazelbuild/rules_apple.git",
)

git_repository(
    name = "build_bazel_apple_support",
    commit = "501b4afb27745c4813a88ffa28acd901408014e4",
    remote = "https://github.com/bazelbuild/apple_support.git",
)

load(
    "@build_bazel_rules_apple//apple:repositories.bzl",
    "apple_rules_dependencies",
)

apple_rules_dependencies()

load(
    "@build_bazel_apple_support//lib:repositories.bzl",
    "apple_support_dependencies",
)

apple_support_dependencies()

load("@com_grail_bazel_toolchain//toolchain:deps.bzl", "bazel_toolchain_dependencies")

bazel_toolchain_dependencies()

load("@com_grail_bazel_toolchain//toolchain:rules.bzl", "llvm_toolchain")

llvm_toolchain(
    name = "llvm_toolchain",
    llvm_version = "8.0.0",
)

load("@llvm_toolchain//:toolchains.bzl", "llvm_register_toolchains")

llvm_register_toolchains()
