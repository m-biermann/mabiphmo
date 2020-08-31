//
// Created by max on 8/17/20.
//

#ifndef HTTPSERVER_IHANDLERCONTEXT_H
#define HTTPSERVER_IHANDLERCONTEXT_H

namespace mabiphmo::httpServer::handler{
	class IHandlerContext{
		virtual ~IHandlerContext() = 0;
	};

	IHandlerContext::~IHandlerContext() = default;
}

#endif //HTTPSERVER_IHANDLERCONTEXT_H
