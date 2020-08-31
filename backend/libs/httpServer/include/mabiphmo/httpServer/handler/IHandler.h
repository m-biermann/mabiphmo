//
// Created by max on 8/17/20.
//

#ifndef HTTPSERVER_IHANDLER_H
#define HTTPSERVER_IHANDLER_H

#include <boost/beast/http/parser.hpp>
#include <boost/beast/http/empty_body.hpp>
#include "IRequestContext.h"
#include "HandlerResult.h"

namespace mabiphmo::httpServer::handler{
	class IHandler{
		virtual HandlerResult Handle(
				boost::beast::http::request_parser<boost::beast::http::empty_body> &request,
				IRequestContext &layerContext) = 0;
	};
}

#endif //HTTPSERVER_IHANDLER_H
