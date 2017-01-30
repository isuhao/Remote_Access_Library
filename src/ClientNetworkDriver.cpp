#include "ClientNetworkDriver.h"
#include "Shapes.h"
#include "IClientDriver.h"
#include "turbojpeg.h"
#include "Input.h"
#include "Logging.h"
#include "Configs.h"
#include "ISocket.h"
#include "INetworkHandlers.h"

#include <assert.h>

namespace SL {
	namespace Remote_Access_Library {
		class ClientNetworkDriverImpl {

		};
		//class ClientNetworkDriverImpl : public INetworkHandlers {

		//	IClientDriver* _IClientDriver;
		//	std::shared_ptr<Client_Config> _Config;
		//	std::shared_ptr<ISocket> _Socket;
		//	std::string _dst_host;
		//

		//	void MouseImage(const std::shared_ptr<ISocket>& socket, const char* data, size_t len) {
		//		auto imgsize = (Point*)p->Payload;
		//		auto img(Image::CreateImage(imgsize->Y, imgsize->X, p->Payload + sizeof(Rect), 4));
		//		_IClientDriver->OnReceive_MouseImage(img);
		//	}

		//	void MousePos(const std::shared_ptr<ISocket>& socket, const char* data, size_t len) {
		//		assert(p->Payload_Length == sizeof(Point));
		//		_IClientDriver->OnReceive_MousePos((Point*)p->Payload);
		//	}
		//	void ScreenImageDif(const std::shared_ptr<ISocket>& socket, const char* data, size_t len) {
		//		auto imgrect = (Rect*)p->Payload;
		//		auto compfree = [](void* handle) {tjDestroy(handle); };
		//		auto _jpegDecompressor(std::unique_ptr<void, decltype(compfree)>(tjInitDecompress(), compfree));

		//		int jpegSubsamp(0), outwidth(0), outheight(0);
		//		auto src = (unsigned char*)(p->Payload + sizeof(Rect));

		//		if (tjDecompressHeader2(_jpegDecompressor.get(), src, static_cast<unsigned long>(p->Payload_Length - sizeof(Rect)), &outwidth, &outheight, &jpegSubsamp) == -1) {
		//			SL_RAT_LOG(Logging_Levels::ERROR_log_level, tjGetErrorStr());
		//		}
		//		auto img = Image::CreateImage(outheight, outwidth);

		//		if (tjDecompress2(_jpegDecompressor.get(), src, static_cast<unsigned long>(p->Payload_Length - sizeof(Rect)), (unsigned char*)img->data(), outwidth, 0, outheight, TJPF_RGBX, TJFLAG_FASTDCT | TJFLAG_NOREALLOC) == -1) {
		//			SL_RAT_LOG(Logging_Levels::ERROR_log_level, tjGetErrorStr());
		//		}
		//		_IClientDriver->OnReceive_ImageDif(imgrect->Origin, img);

		//	}
		//	void ScreenImage(const std::shared_ptr<ISocket>& socket, const char* data, size_t len) {

		//		auto compfree = [](void* handle) {tjDestroy(handle); };
		//		auto _jpegDecompressor(std::unique_ptr<void, decltype(compfree)>(tjInitDecompress(), compfree));
		//		int jpegSubsamp(0), outwidth(0), outheight(0);
		//		auto src = (unsigned char*)(p->Payload + sizeof(Rect));

		//		if (tjDecompressHeader2(_jpegDecompressor.get(), src, static_cast<unsigned long>(p->Payload_Length - sizeof(Rect)), &outwidth, &outheight, &jpegSubsamp) == -1) {
		//			SL_RAT_LOG(Logging_Levels::ERROR_log_level, "tjDecompressHeader2 " << tjGetErrorStr());
		//		}
		//		auto img = Image::CreateImage(outheight, outwidth);

		//		if (tjDecompress2(_jpegDecompressor.get(), src, static_cast<unsigned long>(p->Payload_Length - sizeof(Rect)), (unsigned char*)img->data(), outwidth, 0, outheight, TJPF_RGBX, TJFLAG_FASTDCT | TJFLAG_NOREALLOC) == -1) {
		//			SL_RAT_LOG(Logging_Levels::ERROR_log_level, tjGetErrorStr());
		//		}
		//		_IClientDriver->OnReceive_Image(img);

		//	}
		//	void ClipboardTextEvent(const std::shared_ptr<ISocket>& socket, const char* data, size_t len) {

		//		_IClientDriver->OnReceive_ClipboardText(p->Payload, p->Payload_Length);
		//	}

		//public:
		//	ClientNetworkDriverImpl(IClientDriver* r, std::shared_ptr<Client_Config> config, const char * dst_host) :
		//		_IClientDriver(r), _Config(config), _dst_host(dst_host) {
		//
		//	}

		//	void Start() {
		//		Stop();
		//		Connect(_Config.get(), this, _dst_host.c_str());


		//	}

		//	void Stop() {
		//		if (_Socket) {
		//			_Socket->close("Stopping Listener");
		//			_Socket.reset();//decrement count
		//		}
		//	}
		//	virtual ~ClientNetworkDriverImpl() {
		//		Stop();
		//	}

		//	virtual void onConnection(const std::shared_ptr<ISocket>& socket) override {
		//		_Socket = socket;
		//		_IClientDriver->onConnection(socket);
		//	}

		//	virtual void onDisconnection(const ISocket* socket) override {
		//		_IClientDriver->onDisconnection(socket);
		//	}

		//	virtual void onMessage(const std::shared_ptr<ISocket>& socket, const char* data, size_t len)  override {
		//		auto p = *reinterpret_cast<const PACKET_TYPES*>(data);
		//		switch (p) {
		//		case PACKET_TYPES::SCREENIMAGE :
		//			ScreenImage(socket, data + sizeof(p), len-sizeof(p));
		//			break;
		//		case PACKET_TYPES::SCREENIMAGEDIF:
		//			ScreenImageDif(socket, data + sizeof(p), len - sizeof(p));
		//			break;
		//		case PACKET_TYPES::MOUSEIMAGE :
		//			MouseImage(socket, data + sizeof(p), len - sizeof(p));
		//			break;
		//		case PACKET_TYPES::MOUSEPOS:
		//			MousePos(socket, data + sizeof(p), len - sizeof(p));
		//			break;
		//		case PACKET_TYPES::CLIPBOARDTEXTEVENT :
		//			ClipboardTextEvent(socket, data + sizeof(p), len - sizeof(p));
		//			break;
		//		default:
		//			_IClientDriver->onMessage(socket, data, len);//pass up the chain
		//			break;
		//		}

		//	}

	
		//	void SendMouse(const MouseEvent& m) {
		//		if (!_Socket) {
		//			SL_RAT_LOG(Logging_Levels::INFO_log_level, "SendMouse called on a socket that is not open yet");
		//			return;
		//		}
		//		if (_Socket->is_loopback()) return;//dont send mouse info to ourselfs as this will cause a loop
		//		//do checks to prevent sending redundant mouse information about its position
		//		if (m.EventData == NO_EVENTDATA && _LastMousePosition == m.Pos && m.PressData == Input::Mouse::NO_PRESS_DATA && m.ScrollDelta == 0) {
		//			return;//already did this event
		//		}
		//		_LastMousePosition = m.Pos;
		//		Packet p(static_cast<unsigned int>(PACKET_TYPES::MOUSEEVENT), sizeof(m));
		//		memcpy(p.Payload, &m, sizeof(m));
		//		_Socket->send(p);
		//	}
		//	void SendKey(const KeyEvent & m) {
		//		if (!_Socket) {
		//			SL_RAT_LOG(Logging_Levels::INFO_log_level, "SendKey called on a socket that is not open yet");
		//			return;
		//		}
		//		Packet p(static_cast<unsigned int>(PACKET_TYPES::KEYEVENT), sizeof(m));
		//		memcpy(p.Payload, &m, sizeof(m));
		//		_Socket->send(p);
		//	}
		//	void SendClipboardText(const char* data, unsigned int len) {
		//		if (!_Socket) {
		//			SL_RAT_LOG(Logging_Levels::INFO_log_level, "SendKey called on a socket that is not open yet");
		//			return;
		//		}
		//		if (_Socket->is_loopback()) return;//dont send clipboard info to ourselfs as it will cause a loop
		//		Packet p(static_cast<unsigned int>(PACKET_TYPES::CLIPBOARDTEXTEVENT), len, (char*)data, false);
		//		_Socket->send(p);
		//	}
		//	std::shared_ptr<ISocket> get_Socket()const {
		//		return _Socket;
		//	}
		//};

	}
}


SL::Remote_Access_Library::ClientNetworkDriver::ClientNetworkDriver(IClientDriver * r, std::shared_ptr<Client_Config> config, const char * dst_host) 
	//: _ClientNetworkDriverImpl(new ClientNetworkDriverImpl(r, config, dst_host))
{

}

SL::Remote_Access_Library::ClientNetworkDriver::~ClientNetworkDriver()
{
	Stop();
	delete _ClientNetworkDriverImpl;
}

void SL::Remote_Access_Library::ClientNetworkDriver::Start()
{
	//_ClientNetworkDriverImpl->Start();
}

void SL::Remote_Access_Library::ClientNetworkDriver::Stop()
{
	//_ClientNetworkDriverImpl->Stop();
}

void SL::Remote_Access_Library::ClientNetworkDriver::SendKey(const KeyEvent & m)
{
	//_ClientNetworkDriverImpl->SendKey(m);
}

void SL::Remote_Access_Library::ClientNetworkDriver::SendMouse(const MouseEvent& m)
{
	//_ClientNetworkDriverImpl->SendMouse(m);
}


void SL::Remote_Access_Library::ClientNetworkDriver::SendClipboardText(const char* data, unsigned int len) {
	//return _ClientNetworkDriverImpl->SendClipboardText(data, len);
}