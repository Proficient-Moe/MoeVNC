using System;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Net.Sockets;
using System.Text;
using System.Threading;

namespace MoeVNC;
{
	//Defines constants and methods for RFB protocol
	class Rfbprot
	{
	public:
		// Encoding Constants
		public const int RAW_ENCODE      = 0;
		public const int COPYRECT_ENCODE = 1;
		public const int RRE_ENCODE      = 2;
		public const int HEXTILE_ENCODE  = 5;
		public const int TRLE_ENCODE     = 15;
		public const int ZRLE_ENCODE     = 16;

		// Server to Client Messages
		public const int FRAMEBUFFERUPDATE  = 0;
		public const int SETCOLORMAPENTRIES = 1;
		public const int BELL               = 2;
		public const int SERVERCUTTEXT      = 3;

		// Client to Server Messages
		public const int SETPIXELFORMAT     = 0;
		public const int SETENCODES         = 2;
		public const int FRAMEBUFFERUPDATEREQUEST = 3;
		public const int KEYEVENT           = 4;
		public const int POINTEREVENT       = 5;
		public const int CLIENTCUTTEXT      = 6;

		// Keyboard Input Constants
		public const int BKSPACE            = 0xff08;
		public const int TAB                = 0xff09;
		public const int ENTER              = 0xff0d;
		public const int ESCAPE             = 0xff1b;
		public const int INSERT             = 0xff63;
		public const int DELETE             = 0xffff;
		public const int HOME               = 0xff50;
		public const int END                = 0xff57;
		public const int PGUP               = 0xff55;
		public const int PGDWN              = 0xff56;
		public const int LEFT               = 0xff51;
		public const int UP                 = 0xff52;
		public const int RIGHT              = 0xff53;
		public const int DOWN               = 0xff54;
		public const int F1                 = 0xFFBE;
        public const int F2                 = 0xFFBF;
        public const int F3                 = 0xFFC0;
        public const int F4                 = 0xFFC1;
        public const int F5                 = 0xFFC2;
        public const int F6                 = 0xFFC3;
        public const int F7                 = 0xFFC4;
        public const int F8                 = 0xFFC5;
        public const int F9                 = 0xFFC6;
        public const int F10                = 0xFFC7;
        public const int F11                = 0xFFC8;
        public const int F12                = 0xFFC9;
        public const int LSHIFT             = 0xFFE1;
        public const int RSHIFT             = 0xFFE2;
        public const int LCTRL              = 0xFFE3;
        public const int RCTRL              = 0xFFE4;
        public const int LMETA              = 0xFFE7;
        public const int RMETA              = 0xFFE8;
        public const int LALT               = 0xFFE9;
        public const int RALT               = 0xFFEA;
        public const int LSUPER             = 0xFFEB;
        public const int RSUPER             = 0xFFEC;
        public const int LHYPER             = 0xFFED;
        public const int RHYPER             = 0xFFEE;
        //End Constants

        private int verMajor;  //First digit of version #
        private int verMinor;   //Second digit of version #

        private TcpClient client;

	};
}