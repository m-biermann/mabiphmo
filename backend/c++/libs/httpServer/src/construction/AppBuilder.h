//
// Created by max on 8/17/20.
//

#ifndef HTTPSERVER_APPBUILDER_H
#define HTTPSERVER_APPBUILDER_H

#include <mabiphmo/httpServer/construction/IAppBuilder.h>

namespace mabiphmo::httpServer::construction{
	class AppBuilder : public IAppBuilder {
		iocServer::construction::IAppBuilder &baseBuilder_;
	protected:
		iocServer::construction::IAppBuilder &BaseBuilder() override;
	public:
		explicit AppBuilder(iocServer::construction::IAppBuilder &baseBuilder);
		IAppBuilder &WithClearText(unsigned int portNr, boost::asio::ip::address &&address) override;
		IAppBuilder &WithThreadCount(unsigned int threadCount) override;
		IAppBuilder &WithSsl(boost::filesystem::path &&fullChainPath, boost::filesystem::path &&privateKeyPath, unsigned int portNr, boost::asio::ip::address &&address) override;
		IAppBuilder &WithHostname(std::string &&hostname) override;
	};
}

#endif //HTTPSERVER_APPBUILDER_H
