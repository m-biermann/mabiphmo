//
// Created by max on 8/17/20.
//

#include "AppBuilder.h"

namespace mabiphmo::httpServer::construction{

	iocServer::construction::IAppBuilder &AppBuilder::BaseBuilder() {
		return baseBuilder_;
	}

	AppBuilder::AppBuilder(iocServer::construction::IAppBuilder &baseBuilder) : baseBuilder_(baseBuilder) {}

	IAppBuilder &AppBuilder::WithClearText(unsigned int portNr, boost::asio::ip::address &&address) {
		//TODO
		(void)portNr;
		(void)address;
		return *this;
	}

	IAppBuilder &AppBuilder::WithThreadCount(unsigned int threadCount) {
		//TODO
		(void)threadCount;
		return *this;
	}

	IAppBuilder &AppBuilder::WithSsl(boost::filesystem::path &&fullChainPath, boost::filesystem::path &&privateKeyPath,
	                                 unsigned int portNr, boost::asio::ip::address &&address) {
		//TODO
		(void)fullChainPath;
		(void)privateKeyPath;
		(void)portNr;
		(void)address;
		return *this;
	}

	IAppBuilder &AppBuilder::WithHostname(std::string &&hostname) {
		//TODO
		(void)hostname;
		return *this;
	}
}
