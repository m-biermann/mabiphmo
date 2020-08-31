//
// Created by max on 8/17/20.
//

#ifndef HTTPSERVER_IAPPBUILDER_H
#define HTTPSERVER_IAPPBUILDER_H

#include <utility>
#include <mabiphmo/iocServer/construction/IAppBuilder.h>
#include <boost/filesystem/path.hpp>
#include <boost/asio/ip/address.hpp>

namespace mabiphmo::httpServer::construction {
	class IAppBuilder {
	public:
		/// Enables clear text, sets a port for it
		/// \param portNr Port number
		/// \return this for chaining
		virtual IAppBuilder &WithClearText(unsigned int portNr, boost::asio::ip::address &&address) = 0;

		/// Sets the thread count, (default: 30)
		/// \param threadCount Thread count
		/// \return this for chaining
		virtual IAppBuilder &WithThreadCount(unsigned int threadCount) = 0;

		/// Enables SSL
		/// \param fullChainPath Path to the file containing the full chain
		/// \param privateKeyPath Path to the file containing the private key
		/// \param portNr Port number
		/// \return this for chaining
		virtual IAppBuilder &
		WithSsl(boost::filesystem::path &&fullChainPath, boost::filesystem::path &&privateKeyPath, unsigned int portNr, boost::asio::ip::address &&address) = 0;

		/// Sets the hostname to match with HTTP Header (default: ignore header)
		/// \param hostname Hostname to match with HTTP Header
		/// \return this for chaining
		virtual IAppBuilder &WithHostname(std::string &&hostname) = 0;

		template <class TService,
				typename ...TDependencies,
				typename... TArgs>
		IAppBuilder &WithService(TArgs &&...args){
			BaseBuilder().WithService<TService, TDependencies...>(std::forward<TArgs>(args)...);
			return *this;
		}

		template <class TInterface, class TService,
				typename ...TDependencies,
				typename... TArgs>
		IAppBuilder &WithServiceOnInterface(TArgs &&...args){
			BaseBuilder().WithServiceOnInterface<TInterface, TService, TDependencies...>(std::forward<TArgs>(args)...);
			return *this;
		}
	protected:
		virtual iocServer::construction::IAppBuilder &BaseBuilder() = 0;
	};
}

#endif //HTTPSERVER_IAPPBUILDER_H
