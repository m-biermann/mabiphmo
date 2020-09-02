//
// Created by max on 8/17/20.
//

#ifndef HTTPSERVER_ICONTEXTHANDLER_H
#define HTTPSERVER_ICONTEXTHANDLER_H

#include <utility>
#include <string>
#include <memory>
#include "IHandler.h"
#include "IHandlerContext.h"

namespace mabiphmo::httpServer::handler{
	template<class Context,
	        typename = typename std::enable_if<std::is_base_of<IHandlerContext, Context>::value>::type>
	class IContextHandler : public IHandler{
		static_assert(std::is_base_of<IHandlerContext, Context>::value);
	public:
		std::shared_ptr<Context> LoadContext(IRequestContext &requestContext){
			return std::dynamic_pointer_cast<Context>(requestContext.LoadLayerContext(Identity()));
		}
	private:
		[[nodiscard]] virtual const std::string &Identity() const = 0;
	protected:
		void StoreContext(IRequestContext &requestContext, Context &&context){
			requestContext.StoreLayerContext(new Context(context), Identity());
		}
	};
}

#endif //HTTPSERVER_ICONTEXTHANDLER_H
