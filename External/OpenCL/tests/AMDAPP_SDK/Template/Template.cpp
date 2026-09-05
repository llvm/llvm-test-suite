/**********************************************************************
Copyright ©2013 Advanced Micro Devices, Inc. All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

•	Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
•	Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or
 other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
 DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
********************************************************************/


#include "Template.hpp"

/*
 * \brief Host Initialization 
 *        Allocate and initialize memory 
 *        on the host. Print input array. 
 */
int
initializeHost(void)
{
    width               = 256;
    input               = NULL;
    output              = NULL;
    multiplier          = 2;

    /////////////////////////////////////////////////////////////////
    // Allocate and initialize memory used by host 
    /////////////////////////////////////////////////////////////////
    cl_uint sizeInBytes = width * sizeof(cl_uint);
    input = (cl_uint *) malloc(sizeInBytes);
    if(!input)
    {
        std::cout << "Error: Failed to allocate input memory on host\n";
        return SDK_FAILURE;
    }

    output = (cl_uint *) malloc(sizeInBytes);
    if(!output)
    {
        std::cout << "Error: Failed to allocate input memory on host\n";
        return SDK_FAILURE;
    }

    for(cl_uint i = 0; i < width; i++)
        input[i] = i;

    // print input array
    print1DArray(std::string("Input").c_str(), input, width);
    return SDK_SUCCESS;
}

/*
 * Converts the contents of a file into a string
 */
std::string
convertToString(const char *filename)
{
    size_t size;
    char*  str;
    std::string s;

    std::fstream f(filename, (std::fstream::in | std::fstream::binary));

    if(f.is_open())
    {
        size_t fileSize;
        f.seekg(0, std::fstream::end);
        size = fileSize = (size_t)f.tellg();
        f.seekg(0, std::fstream::beg);

        str = new char[size+1];
        if(!str)
        {
            f.close();
            std::cout << "Memory allocation failed";
            return NULL;
        }

        f.read(str, fileSize);
        f.close();
        str[size] = '\0';
    
        s = str;
        delete[] str;
        return s;
    }
    else
    {
        std::cout << "\nFile containg the kernel code(\".cl\") not found. Please copy the required file in the folder containg the executable.\n";
        exit(1);
    }
    return NULL;
}

/*
 * \brief OpenCL related initialization 
 *        Create Context, Device list, Command Queue
 *        Create OpenCL memory buffer objects
 *        Load CL file, compile, link CL source 
 *		  Build program and kernel objects
 */
int
initializeCL(void)
{
    cl_int status = 0;
    size_t deviceListSize;

    //////////////////////////////////////////////////////////////////// 
    // STEP 1 Getting Platform.
    //////////////////////////////////////////////////////////////////// 
    
    /*
     * Have a look at the available platforms and pick either
     * the AMD one if available or a reasonable default.
     */

    cl_uint numPlatforms;
    cl_platform_id platform = NULL;
    status = clGetPlatformIDs(0, NULL, &numPlatforms);
    if(status != CL_SUCCESS)
    {
        std::cout << "Error: Getting Platforms. (clGetPlatformsIDs)\n";
        return SDK_FAILURE;
    }
    
    if(numPlatforms > 0)
    {
        cl_platform_id* platforms = new cl_platform_id[numPlatforms];
        status = clGetPlatformIDs(numPlatforms, platforms, NULL);
        if(status != CL_SUCCESS)
        {
            std::cout << "Error: Getting Platform Ids. (clGetPlatformsIDs)\n";
            return SDK_FAILURE;
        }
        for(unsigned int i=0; i < numPlatforms; ++i)
        {
            char pbuff[100];
            status = clGetPlatformInfo(
                        platforms[i],
                        CL_PLATFORM_VENDOR,
                        sizeof(pbuff),
                        pbuff,
                        NULL);
            if(status != CL_SUCCESS)
            {
                std::cout << "Error: Getting Platform Info.(clGetPlatformInfo)\n";
                return SDK_FAILURE;
            }
            platform = platforms[i];
            if(!strcmp(pbuff, "Advanced Micro Devices, Inc."))
            {
                break;
            }
        }
        delete platforms;
    }

    if(NULL == platform)
    {
        std::cout << "NULL platform found so Exiting Application." << std::endl;
        return SDK_FAILURE;
    }


    //////////////////////////////////////////////////////////////////// 
    // STEP 2 Creating context using the platform selected
    //      Context created from type includes all available
    //      devices of the specified type from the selected platform 
    //////////////////////////////////////////////////////////////////// 
    

    /*
     * If we could find our platform, use it. Otherwise use just available platform.
     */
    cl_context_properties cps[3] = { CL_CONTEXT_PLATFORM, (cl_context_properties)platform, 0 };

    context = clCreateContextFromType(cps, 
                                      CL_DEVICE_TYPE_GPU, 
                                      NULL, 
                                      NULL, 
                                      &status);
    if(status != CL_SUCCESS) 
    {  
        std::cout << "Error: Creating Context. (clCreateContextFromType)\n";
        return SDK_FAILURE; 
    }


    //////////////////////////////////////////////////////////////////// 
    // STEP 3
    //      3.1 Query context for the device list size,
    //      3.2 Allocate that much memory using malloc or new
    //      3.3 Again query context info to get the array of device
    //              available in the created context
    //////////////////////////////////////////////////////////////////// 
    
    // First, get the size of device list data
    status = clGetContextInfo(context, 
                              CL_CONTEXT_DEVICES, 
                              0, 
                              NULL, 
                              &deviceListSize);
    if(status != CL_SUCCESS) 
    {  
        std::cout <<
            "Error: Getting Context Info \
            (device list size, clGetContextInfo)\n";
        return SDK_FAILURE;
    }

    devices = (cl_device_id *)malloc(deviceListSize);
    if(devices == 0)
    {
        std::cout << "Error: No devices found.\n";
        return SDK_FAILURE;
    }

    // Now, get the device list data
    status = clGetContextInfo(
                 context, 
                 CL_CONTEXT_DEVICES, 
                 deviceListSize, 
                 devices, 
                 NULL);
    if(status != CL_SUCCESS) 
    { 
        std::cout <<
            "Error: Getting Context Info \
            (device list, clGetContextInfo)\n";
        return SDK_FAILURE;
    }

    //////////////////////////////////////////////////////////////////// 
    // STEP 4 Creating command queue for a single device
    //      Each device in the context can have a 
    //      dedicated commandqueue object for itself
    //////////////////////////////////////////////////////////////////// 
    
    commandQueue = clCreateCommandQueue(
                       context, 
                       devices[0], 
                       0, 
                       &status);
    if(status != CL_SUCCESS) 
    { 
        std::cout << "Creating Command Queue. (clCreateCommandQueue)\n";
        return SDK_FAILURE;
    }

    /////////////////////////////////////////////////////////////////
    // STEP 5 Creating cl_buffer objects from host buffer
    //          These buffer objects can be passed to the kernel
    //          as kernel arguments
    /////////////////////////////////////////////////////////////////
    inputBuffer = clCreateBuffer(
                      context, 
                      CL_MEM_READ_WRITE | CL_MEM_USE_HOST_PTR,
                      sizeof(cl_uint) * width,
                      input, 
                      &status);
    if(status != CL_SUCCESS) 
    { 
        std::cout << "Error: clCreateBuffer (inputBuffer)\n";
        return SDK_FAILURE;
    }

    outputBuffer = clCreateBuffer(
                       context, 
                       CL_MEM_READ_WRITE | CL_MEM_USE_HOST_PTR,
                       sizeof(cl_uint) * width,
                       output, 
                       &status);
    if(status != CL_SUCCESS) 
    { 
        std::cout << "Error: clCreateBuffer (outputBuffer)\n";
        return SDK_FAILURE;
    }


    /////////////////////////////////////////////////////////////////
    // STEP 6. Building Kernel
    //      6.1 Load CL file, using basic file i/o
    //      6.2 Build CL program object
    //      6.3 Create CL kernel object
    /////////////////////////////////////////////////////////////////
    const char * filename  = "Template_Kernels.cl";
    std::string  sourceStr = convertToString(filename);
    const char * source    = sourceStr.c_str();
    size_t sourceSize[]    = { strlen(source) };

    program = clCreateProgramWithSource(
                  context, 
                  1, 
                  &source,
                  sourceSize,
                  &status);
    if(status != CL_SUCCESS) 
    { 
      std::cout <<
               "Error: Loading Binary into cl_program \
               (clCreateProgramWithBinary)\n";
      return SDK_FAILURE;
    }

    // create a cl program executable for all the devices specified
    status = clBuildProgram(program, 1, devices, NULL, NULL, NULL);
    if(status != CL_SUCCESS) 
    { 
        std::cout << "Error: Building Program (clBuildProgram)\n";
        return SDK_FAILURE; 
    }

    // get a kernel object handle for a kernel with the given name
    kernel = clCreateKernel(program, "templateKernel", &status);
    if(status != CL_SUCCESS) 
    {  
        std::cout << "Error: Creating Kernel from program. (clCreateKernel)\n";
        return SDK_FAILURE;
    }

    return SDK_SUCCESS;
}


/*
 * \brief Run OpenCL program 
 *
 *        Bind host variables to kernel arguments 
 *        Run the CL kernel
 */
int 
runCLKernels(void)
{
    cl_int   status;
    cl_uint maxDims;
    cl_event events[2];
    size_t globalThreads[1];
    size_t localThreads[1];
    size_t maxWorkGroupSize;
    size_t maxWorkItemSizes[3];

    //////////////////////////////////////////////////////////////////// 
    // STEP 7 Analyzing proper workgroup size for the kernel
    //          by querying device information
    //    7.1 Device Info CL_DEVICE_MAX_WORK_GROUP_SIZE
    //    7.2 Device Info CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS
    //    7.3 Device Info CL_DEVICE_MAX_WORK_ITEM_SIZES
    //////////////////////////////////////////////////////////////////// 
    
    
    /**
    * Query device capabilities. Maximum 
    * work item dimensions and the maximmum
    * work item sizes
    */ 
    status = clGetDeviceInfo(
        devices[0], 
        CL_DEVICE_MAX_WORK_GROUP_SIZE, 
        sizeof(size_t), 
        (void*)&maxWorkGroupSize, 
        NULL);
    if(status != CL_SUCCESS) 
    {  
        std::cout << "Error: Getting Device Info. (clGetDeviceInfo)\n";
        return SDK_FAILURE;
    }
    
    status = clGetDeviceInfo(
        devices[0], 
        CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS, 
        sizeof(cl_uint), 
        (void*)&maxDims, 
        NULL);
    if(status != CL_SUCCESS) 
    {  
        std::cout << "Error: Getting Device Info. (clGetDeviceInfo)\n";
        return SDK_FAILURE;
    }

    status = clGetDeviceInfo(
        devices[0], 
        CL_DEVICE_MAX_WORK_ITEM_SIZES, 
        sizeof(size_t)*maxDims,
        (void*)maxWorkItemSizes,
        NULL);
    if(status != CL_SUCCESS) 
    {  
        std::cout << "Error: Getting Device Info. (clGetDeviceInfo)\n";
        return SDK_FAILURE;
    }
    
    globalThreads[0] = width;
    localThreads[0]  = 1;

    if(localThreads[0] > maxWorkGroupSize ||
        localThreads[0] > maxWorkItemSizes[0])
    {
        std::cout << "Unsupported: Device does not support requested number of work items.";
        return SDK_FAILURE;
    }

    //////////////////////////////////////////////////////////////////// 
    // STEP 8 Set appropriate arguments to the kernel
    //    8.1 Kernel Arg outputBuffer ( cl_mem object)
    //    8.2 Kernel Arg inputBuffer (cl_mem object)
    //    8.3 Kernel Arg multiplier (cl_uint)
    //////////////////////////////////////////////////////////////////// 
    
    // the output array to the kernel
    status = clSetKernelArg(
                    kernel, 
                    0, 
                    sizeof(cl_mem), 
                    (void *)&outputBuffer);
    if(status != CL_SUCCESS) 
    { 
        std::cout << "Error: Setting kernel argument. (output)\n";
        return SDK_FAILURE;
    }

    // the input array to the kernel
    status = clSetKernelArg(
                    kernel, 
                    1, 
                    sizeof(cl_mem), 
                    (void *)&inputBuffer);
    if(status != CL_SUCCESS) 
    { 
        std::cout << "Error: Setting kernel argument. (input)\n";
        return SDK_FAILURE;
    }

    // multiplier
    status = clSetKernelArg(
                    kernel, 
                    2, 
                    sizeof(cl_uint), 
                    (void *)&multiplier);
    if(status != CL_SUCCESS) 
    { 
        std::cout << "Error: Setting kernel argument. (multiplier)\n";
        return SDK_FAILURE;
    }

    //////////////////////////////////////////////////////////////////// 
    // STEP 9 Enqueue a kernel run call.
    //          Wait till the event completes and release the event
    //////////////////////////////////////////////////////////////////// 
    status = clEnqueueNDRangeKernel(
                 commandQueue,
                 kernel,
                 1,
                 NULL,
                 globalThreads,
                 localThreads,
                 0,
                 NULL,
                 &events[0]);
    if(status != CL_SUCCESS) 
    { 
        std::cout <<
            "Error: Enqueueing kernel onto command queue. \
            (clEnqueueNDRangeKernel)\n";
        return SDK_FAILURE;
    }


    // wait for the kernel call to finish execution
    status = clWaitForEvents(1, &events[0]);
    if(status != CL_SUCCESS) 
    { 
        std::cout <<
            "Error: Waiting for kernel run to finish. \
            (clWaitForEvents)\n";
        return SDK_FAILURE;
    }

    status = clReleaseEvent(events[0]);
    if(status != CL_SUCCESS) 
    { 
        std::cout <<
            "Error: Release event object. \
            (clReleaseEvent)\n";
        return SDK_FAILURE;
    }

    //////////////////////////////////////////////////////////////////// 
    // STEP 10  Enqueue readBuffer to read the output back
    //  Wait for the event and release the event
    //////////////////////////////////////////////////////////////////// 
    status = clEnqueueReadBuffer(
                commandQueue,
                outputBuffer,
                CL_TRUE,
                0,
                width * sizeof(cl_uint),
                output,
                0,
                NULL,
                &events[1]);
    
    if(status != CL_SUCCESS) 
    { 
        std::cout << 
            "Error: clEnqueueReadBuffer failed. \
             (clEnqueueReadBuffer)\n";
        return SDK_FAILURE;
    }
    
    // Wait for the read buffer to finish execution
    status = clWaitForEvents(1, &events[1]);
    if(status != CL_SUCCESS) 
    { 
        std::cout <<
            "Error: Waiting for read buffer call to finish. \
            (clWaitForEvents)\n";
        return SDK_FAILURE;
    }
    
    status = clReleaseEvent(events[1]);
    if(status != CL_SUCCESS) 
    { 
        std::cout <<
            "Error: Release event object. \
            (clReleaseEvent)\n";
        return SDK_FAILURE;
    }
    return SDK_SUCCESS;
}


/*
 * \brief Release OpenCL resources (Context, Memory etc.) 
 */
int  
cleanupCL(void)
{
    cl_int status;

    //////////////////////////////////////////////////////////////////// 
    // STEP 11  CLean up the opencl resources used 
    //////////////////////////////////////////////////////////////////// 
    
    status = clReleaseKernel(kernel);
    if(status != CL_SUCCESS)
    {
        std::cout << "Error: In clReleaseKernel \n";
        return SDK_FAILURE; 
    }
    status = clReleaseProgram(program);
    if(status != CL_SUCCESS)
    {
        std::cout << "Error: In clReleaseProgram\n";
        return SDK_FAILURE; 
    }
    status = clReleaseMemObject(inputBuffer);
    if(status != CL_SUCCESS)
    {
        std::cout << "Error: In clReleaseMemObject (inputBuffer)\n";
        return SDK_FAILURE; 
    }
    status = clReleaseMemObject(outputBuffer);
    if(status != CL_SUCCESS)
    {
        std::cout << "Error: In clReleaseMemObject (outputBuffer)\n";
        return SDK_FAILURE; 
    }
    status = clReleaseCommandQueue(commandQueue);
    if(status != CL_SUCCESS)
    {
        std::cout << "Error: In clReleaseCommandQueue\n";
        return SDK_FAILURE;
    }
    status = clReleaseContext(context);
    if(status != CL_SUCCESS)
    {
        std::cout << "Error: In clReleaseContext\n";
        return SDK_FAILURE;
    }
    return SDK_SUCCESS;
}


/* 
 * \brief Releases program's resources 
 */
void
cleanupHost(void)
{
    if(input != NULL)
    {
        free(input);
        input = NULL;
    }
    if(output != NULL)
    {
        free(output);
        output = NULL;
    }
    if(devices != NULL)
    {
        free(devices);
        devices = NULL;
    }
}


/*
 * \brief Print no more than 256 elements of the given array.
 *
 *        Print Array name followed by elements.
 */
void print1DArray(
         const std::string arrayName, 
         const unsigned int * arrayData, 
         const unsigned int length)
{
    cl_uint i;
    cl_uint numElementsToPrint = (256 < length) ? 256 : length;

    std::cout << std::endl;
    std::cout << arrayName << ":" << std::endl;
    for(i = 0; i < numElementsToPrint; ++i)
    {
        std::cout << arrayData[i] << " ";
    }
    std::cout << std::endl;

}

void verify()
{
    bool passed = true;
    for(unsigned int i = 0; i < width; ++i)
        if(input[i] * multiplier != output[i])
            passed = false;

    if(passed == true)
        std::cout << "Passed!\n" << std::endl;
    else
        std::cout << "Failed!\n" << std::endl;
}

int 
main(int argc, char * argv[])
{
    // Initialize Host application 
    if(initializeHost() != SDK_SUCCESS)
        return SDK_FAILURE;

    // Initialize OpenCL resources
    if(initializeCL() != SDK_SUCCESS)
        return SDK_FAILURE;

    // Run the CL program
    if(runCLKernels() != SDK_SUCCESS)
        return SDK_FAILURE;

    // Print output array
    print1DArray(std::string("Output"), output, width);

    // Verify output
    verify();

    // Releases OpenCL resources 
    if(cleanupCL()!= SDK_SUCCESS)
        return SDK_FAILURE;

    // Release host resources
    cleanupHost();

    return SDK_SUCCESS;
}
