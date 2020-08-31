//
// Created by max on 8/17/20.
//

#ifndef HTTPSERVER_IREQUESTCONTEXT_H
#define HTTPSERVER_IREQUESTCONTEXT_H

#include <string>
#include <memory>
#include <boost/beast/http/parser.hpp>
#include <boost/beast/http/empty_body.hpp>
#include "IHandlerContext.h"
#include "Sender.h"

namespace mabiphmo::httpServer::handler{
	class IRequestContext{
	public:
		[[nodiscard]] virtual ISender &Sender() const = 0;

		virtual boost::beast::http::request_parser<boost::beast::http::empty_body> &RequestParser() = 0;

		virtual void StoreLayerContext(IHandlerContext *data, std::string &location) = 0;
		virtual std::shared_ptr<IHandlerContext> LoadLayerContext(std::string &location) = 0;
	};
}

#endif //HTTPSERVER_IREQUESTCONTEXT_H
