#pragma once
class HelloTriangle {
public:
	void run();
private:
	GLFWwindow* window;
	const uint32_t WIDTH = 800;
	const uint32_t HEIGHT = 600;

	void initWindow();
	void initVulkan();
	void mainLoop();
	void cleanup();

	VkInstance instance;
	void createInstance();
};
