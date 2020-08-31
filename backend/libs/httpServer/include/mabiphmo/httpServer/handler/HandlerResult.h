//
// Created by max on 8/18/20.
//

#ifndef HTTPSERVER_HANDLERRESULT_H
#define HTTPSERVER_HANDLERRESULT_H

#include "Sender.h"
#include <boost/beast/core/tcp_stream.hpp>
#include <boost/beast/ssl/ssl_stream.hpp>
#include <iostream>

namespace mabiphmo::httpServer::handler{
	class HandlerResult{
		std::shared_ptr<void> data_;
		std::function<void()> sendLambda_;
	public:
		template<class Body>
		HandlerResult(ISender &sender, boost::beast::http::response<Body> &&message) : data_(std::static_pointer_cast<void>(std::make_shared<boost::beast::http::response<Body>>(message)))
		{
			try{
				auto& typedSender = dynamic_cast<Sender<boost::beast::tcp_stream>&>(sender);
				sendLambda_ = [typedSender, this](){
					typedSender.Send(*std::static_pointer_cast<boost::beast::http::response<Body>>(data_));
				};
			}
			catch(const std::bad_cast& e)
			{
				auto& typedSender = dynamic_cast<Sender<boost::beast::ssl_stream<boost::beast::tcp_stream>>&>(sender);
				sendLambda_ = [typedSender, this](){
					typedSender.Send(*std::static_pointer_cast<boost::beast::http::response<Body>>(data_));
				};
			}
		}

		void Send(){sendLambda_();}
	};
}

#endif //HTTPSERVER_HANDLERRESULT_H
