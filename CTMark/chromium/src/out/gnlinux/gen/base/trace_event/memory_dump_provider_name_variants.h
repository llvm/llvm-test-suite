// Generated from generate_allowlist_from_histograms_file.py. Do not edit!

#ifndef BASE_TRACE_EVENT_MEMORY_DUMP_PROVIDER_NAME_VARIANTS_H_
#define BASE_TRACE_EVENT_MEMORY_DUMP_PROVIDER_NAME_VARIANTS_H_

#include <algorithm>
#include <string_view>

namespace trace_event_metrics {

inline constexpr std::string_view kMemoryDumpProviderNameAllowList[] = {
  "AXPlatformNode",
  "AXPlatformNodeWin",
  "AllProviders",
  "AndroidGraphics",
  "AutocompleteController",
  "BlinkGC",
  "BlinkObjectCounters",
  "BlobStorageContext",
  "BucketContext",
  "Canvas",
  "ClientDiscardableSharedMemoryManager",
  "CommandBuffer",
  "ContextProviderCommandBuffer",
  "DOMStorage",
  "DawnCache",
  "DawnSharedContext",
  "DevTools",
  "DevToolsManager",
  "DevtoolsDurableMessageCollectorManager",
  "DiscardableSharedMemoryManager",
  "DownloadService",
  "ExtensionFunctions",
  "FontCaches",
  "FrameBufferPool",
  "FrameEvictionManager",
  "GpuPersistentCache",
  "GrShaderCache",
  "GraphiteVizMemoryAssistant",
  "IPCChannel",
  "InMemoryURLIndex",
  "IndexedDBBackingStore",
  "JavaHeap",
  "LevelDB",
  "LeveldbValueStore",
  "LocalStorage",
  "LocalStorageSqlite",
  "MadvFreeDiscardableMemoryAllocator",
  "Malloc",
  "MappableSharedImageVideoFramePool",
  "MemoryCache",
  "MojoHandleTable",
  "MojoLevelDB",
  "MojoMessages",
  "Orderfile",
  "ParkableImages",
  "ParkableStrings",
  "PartitionAlloc",
  "PartitionAlloc.AddressSpace",
  "SessionStorage",
  "SessionStorageSqlite",
  "SharedContextState",
  "SharedImageManager",
  "SharedMemoryTracker",
  "Skia",
  "Sql",
  "TabRestoreServiceHelper",
  "TestDumpProvider",
  "TestDumpProvider.Allowlisted",
  "TextureOwner",
  "TileManager",
  "V8Isolate",
  "V8SharedMemory",
  "WebGL",
  "WebMediaPlayer_MainThread",
  "WebMediaPlayer_MediaThread",
  "WebNN",
  "android__ResourceManagerImpl",
  "android_meminfo",
  "cc__GpuImageDecodeCache",
  "cc__ResourcePool",
  "cc__ResourceProvider",
  "cc__SoftwareImageDecodeCache",
  "cc__StagingBufferPool",
  "gpu__BufferManager",
  "gpu__RenderbufferManager",
  "gpu__ServiceTransferCache",
  "gpu__TextureManager",
  "gpu__TransferBufferManager",
  "hibernated_canvas",
  "media__V4l2VideoDecodeAccelerator",
  "media__VaapiVideoEncodeAccelerator",
  "media__VideoResourceUpdater",
  "sql__Database",
  "vulkan",
};

constexpr bool IsValidMemoryDumpProviderName(std::string_view s) {
  return std::binary_search(
    std::cbegin(kMemoryDumpProviderNameAllowList),
    std::cend(kMemoryDumpProviderNameAllowList),
    s);
}

}  // namespace trace_event_metrics

#endif  // BASE_TRACE_EVENT_MEMORY_DUMP_PROVIDER_NAME_VARIANTS_H_
