@set binPath=D:/VulkanSDK/Bin
@echo binPath: %binPath%

%binPath%/glslc.exe ./shaders/shader.vert -o ./shaders/vert.spv -S
%binPath%/glslc.exe ./shaders/shader.frag -o ./shaders/frag.spv -S
@pause