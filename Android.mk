LOCAL_PATH := $(call my-dir)

ifeq ($(call is-board-platform-in-list,msm8974 msm8960 msm8660),true)
    include $(call all-subdir-makefiles,$(LOCAL_PATH))
endif