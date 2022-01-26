# 3 Drawing!

REMEMBER to add dxguid.lib in properties.

For those who are transitioning from previous tutorial note that we had "closed" our commandList at the time of its creation in the prev tut. But here we are recording the commandList with commands for copying vertex data from upload heap to default heap. Therefore we should remove that "commandList->Close()" statement at the time of commandList's creation.

A small difference people might not notice when transitioning from the previous tutorial to this one is hr = commandList->Reset(commandAllocator[frameIndex], pipelineStateObject); - the fact that nullptr was changed to the pso pointer.

url: 

https://www.braynzarsoft.net/viewtutorial/q16390-04-direct3d-12-drawing