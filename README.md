# 5 Draw quad 

add index buffer. same operation as vertex buffer : create default heap, upload heap, uploadsubresource, store the GPU virtual address in index buffer view. then in updatePipeline function, add new function (set index buffer) in commandList, and change draw call function to DrawIndexedInstanced() 


url: 

https://www.braynzarsoft.net/viewtutorial/q16390-directx-12-index-buffers