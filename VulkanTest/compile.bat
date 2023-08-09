@set binPath=D:/VulkanSDK/Bin
@echo binPath: %binPath%

%binPath%/glslc.exe ./shaders/shader.vert -o vert.spv -S
%binPath%/glslc.exe ./shaders/shader.frag -o frag.spv -S
@pause