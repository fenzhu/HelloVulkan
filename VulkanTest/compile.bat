@set binPath=C:/DevEnvironment/VulkanSDK/1.3.275/Bin
@REM D:/VulkanSDK/Bin
@echo binPath: %binPath%

%binPath%/glslc.exe ./shaders/shader.vert -o ./shaders/vert.spv 
%binPath%/glslc.exe ./shaders/shader.frag -o ./shaders/frag.spv 
@pause