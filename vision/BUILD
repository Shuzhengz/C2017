load("//third_party/google/protobuf:protobuf.bzl", "cc_proto_library")

cc_library(
    name = "vision_queues",
    hdrs = ["queue_types.h"],
    deps = [
        ":vision_proto",
        "//muan/proto:stack_proto",
        "//muan/queues:queues"
    ],
    visibility = ["//visibility:public"]
)

cc_proto_library(
    name = "vision_proto",
    srcs = ["vision.proto"],
    protoc = "//third_party/google/protobuf:protoc",
    default_runtime = "//third_party/google/protobuf",
    visibility = ["//visibility:public"],
)
