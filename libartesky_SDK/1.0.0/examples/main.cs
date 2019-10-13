using System;
using System.Threading;
using System.Runtime.InteropServices;

namespace libartesky
{
    class CsExample
    {
        // C++ DLL file path respect to exe CS file position
#if x64
        public const string DLL_FILE_NAME = "../../../../lib/x64/Release/libarteskyc_x64.dll";
#elif WIN32
        public const string DLL_FILE_NAME = "../../../../lib/Win32/Release/libarteskyc.dll";
#endif

        [DllImport(DLL_FILE_NAME)]
        public static extern uint flatLoad();

        [DllImport(DLL_FILE_NAME, CallingConvention = CallingConvention.Cdecl)]
        public static extern uint flatConnect(ref string portName, ref bool async);

        [DllImport(DLL_FILE_NAME, CallingConvention = CallingConvention.Cdecl)]
        public static extern uint flatDisconnect();

        [DllImport(DLL_FILE_NAME, CallingConvention = CallingConvention.Cdecl)]
        public static extern uint getSerialPort(ref string serialPort);

        [DllImport(DLL_FILE_NAME, CallingConvention = CallingConvention.Cdecl)]
        public static extern uint isFlatConnected(ref bool isConnected);

        [DllImport(DLL_FILE_NAME, CallingConvention = CallingConvention.Cdecl)]
        public static extern uint turnOn();

        [DllImport(DLL_FILE_NAME, CallingConvention = CallingConvention.Cdecl)]
        public static extern uint turnOff();

        [DllImport(DLL_FILE_NAME, CallingConvention = CallingConvention.Cdecl)]
        public static extern uint setBrightness(ref uint level);

        [DllImport(DLL_FILE_NAME, CallingConvention = CallingConvention.Cdecl)]
        public static extern uint getBrightness(ref uint level);

        [DllImport(DLL_FILE_NAME, CallingConvention = CallingConvention.Cdecl)]
        public static extern uint getStatus(ref bool status);

        [DllImport(DLL_FILE_NAME, CallingConvention = CallingConvention.Cdecl)]
        public static extern uint getAPIversion(ref string version);

        static void Main()
        {
            uint _ret = 0;                  //API return value, 0 = no error
            string _version = "";           //API version in major.minor.patch.build format
            string _portName = "COM3";      //Port name, for example "COM3"
            bool _async = false;            //Connection behaviour, false = synchronous connection
            bool _isConnected = false;      //Connection check, true = flat box is connected
            uint _level = 100;              //Brightness level, range = [0, 255]
            bool _status = false;           //Lamp status, false = switched off

            Console.WriteLine("libartesky CS wrapper test");
            //DLL starting up
            flatLoad();
            //Get API version
            getAPIversion(ref _version);
            Console.WriteLine("version: " + _version);
            //Open connection with the ARTESKY USB Flat Box
            Console.WriteLine("open connection...");
            _ret = flatConnect(ref _portName, ref _async);
            if(_ret == 0)
                Console.WriteLine("connection opened");
            else
                Console.WriteLine("flatConnect: library error");
            Thread.Sleep(2000);             //Maximum bootloader starting up time
            //Get serial port name
            _portName = "";
            _ret = getSerialPort(ref _portName);
            if (_ret == 0)
                Console.WriteLine("serial port: " + _portName);
            else
                Console.WriteLine("getSerialPort: library error");
            //Check if the ARTESKY USB Flat Box is connected
            _ret = isFlatConnected(ref _isConnected);
            if (_ret == 0)
            {
                if (_isConnected)
                    Console.WriteLine("flat box connected");
                else
                    Console.WriteLine("flat box is disconnected");
            }
            else
                Console.WriteLine("isFlatConnected: library error");
            //Switch lamp on
            _ret = turnOn();
            if (_ret == 0)
                Console.WriteLine("Lamp switched on");
            else
                Console.WriteLine("turnOn: library error");
            //Set lamp brightness
            _ret = setBrightness(ref _level);
            if (_ret == 0)
                Console.WriteLine("Lamp brightness level set to " + _level);
            else
                Console.WriteLine("setBrightness: library error");
            //Get lamp brightness
            _level = 0;
            _ret = getBrightness(ref _level);
            if (_ret == 0)
                Console.WriteLine("brightness level: " + _level);
            else
                Console.WriteLine("getBrightness: library error");
            //Get lamp status
            _ret = getStatus(ref _status);
            if (_ret == 0)
            {
                if (_status)
                    Console.WriteLine("lamp On");
                else
                    Console.WriteLine("lamp Off");
            }
            else
                Console.WriteLine("getStatus: library error");
            //Switch lamp off
            _ret = turnOff();
            if (_ret == 0)
                Console.WriteLine("Lamp switched off");
            else
                Console.WriteLine("turnOff: library error");
            //Get lamp status
            _ret = getStatus(ref _status);
            if (_ret == 0)
            {
                if (_status)
                    Console.WriteLine("lamp On");
                else
                    Console.WriteLine("lamp Off");
            }
            else
                Console.WriteLine("getStatus: library error");
            //Close connection with the ARTESKY USB Flat Box
            _ret = flatDisconnect();
            if (_ret == 0)
                Console.WriteLine("connection closed");
            else
                Console.WriteLine("flatDisconnect: library error");
            Console.WriteLine("Press any key to exit...");
            Console.ReadKey();
        }
    }
}