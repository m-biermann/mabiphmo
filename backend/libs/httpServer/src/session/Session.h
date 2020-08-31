//
// Created by max on 8/18/20.
//

#ifndef HTTPSERVER_SESSION_H
#define HTTPSERVER_SESSION_H

#include <memory>
#include <mabiphmo/httpServer/handler/IHandler.h>

namespace mabiphmo::httpServer::session{
	template<class Stream>
	class Session {
		Stream stream_;
	public:
		Session(std::shared_ptr<handler::IHandler> handler, Stream &&stream);
	};
}

#endif //HTTPSERVER_SESSION_H
