//
// Created by max on 8/18/20.
//

#ifndef HTTPSERVER_SENDER_H
#define HTTPSERVER_SENDER_H

#include <boost/beast/http.hpp>

namespace mabiphmo::httpServer::handler{
	class ISender{
	public:
		virtual ~ISender() = 0;
	};
	ISender::~ISender() = default;

	template <typename Stream>
	class Sender : public ISender{
		Sender &stream_;
	public:
		explicit Sender(Stream &stream) : stream_(stream){}
		template<class Body>
		void Send(boost::beast::http::response<Body> &message){
			boost::beast::http::async_write(stream_, message);
		}
		~Sender() override = default;
	};
}

#endif //HTTPSERVER_SENDER_H
