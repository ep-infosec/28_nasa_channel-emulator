/* -*- C++ -*- */

//=============================================================================
/**
 * @file   modAOS_VC_Rcv_Interface.cpp
 * @author Tad Kollar  
 *
 * $Id: modAOS_VC_Rcv_Interface.cpp 2018 2013-06-04 14:59:19Z tkollar $
 * Copyright (c) 2009.
 *      NASA Glenn Research Center.  All rights reserved.
 *      See COPYING file that comes with this distribution.
 */
//=============================================================================

#include "modAOS_VC_Rcv.hpp"
#include "AOS_Interface_Macros.hpp"

namespace nAOS_VC_Rcv {

//=============================================================================
/**
 * @class modAOS_VC_Rcv_Interface
 * @author Tad Kollar  
 * @brief Provide an XML-RPC interface to the Virtual Channel Receive module.
 */
//=============================================================================
class modAOS_VC_Rcv_Interface: public nasaCE::TrafficHandler_Interface<modAOS_VC_Rcv> {
public:
	modAOS_VC_Rcv_Interface(xmlrpc_c::registryPtr& rpcRegistry):
		nasaCE::TrafficHandler_Interface<modAOS_VC_Rcv>(rpcRegistry, "modAOS_VC_Rcv") {
		ACE_TRACE("modAOS_VC_Rcv_Interface::modAOS_VC_Rcv_Interface");

		register_methods(rpcRegistry);
	}

	AOS_PHYSICAL_CHANNEL_DEFINE_ACCESSORS();
	AOS_MASTER_CHANNEL_DEFINE_ACCESSORS();
	AOS_VIRTUAL_CHANNEL_DEFINE_ACCESSORS();

	// Export specified methods via XML-RPC.
	void register_methods(xmlrpc_c::registryPtr&);

protected:
	void get_counters_(xmlrpc_c::paramList const& paramList, modAOS_VC_Rcv* handler,
		xstruct& counters) {
		ACE_TRACE("modAOS_VC_Rcv_Interface::get_counters_");

		nasaCE::TrafficHandler_Interface<modAOS_VC_Rcv>::get_counters_(paramList, handler, counters);

		GET_AOS_PHYSICAL_CHANNEL_COUNTERS();
		GET_AOS_MASTER_CHANNEL_COUNTERS();
		GET_AOS_VIRTUAL_CHANNEL_COUNTERS();
	}

	void get_settings_(xmlrpc_c::paramList const& paramList, modAOS_VC_Rcv* handler,
		xstruct& settings) {
		ACE_TRACE("modAOS_VC_Rcv_Interface::get_settings_");

		nasaCE::TrafficHandler_Interface<modAOS_VC_Rcv>::get_settings_(paramList, handler, settings);

		GET_AOS_PHYSICAL_CHANNEL_SETTINGS();
		GET_AOS_MASTER_CHANNEL_SETTINGS();
		GET_AOS_VIRTUAL_CHANNEL_SETTINGS();
	}
};

modAOS_VC_Rcv_Interface* modAOS_VC_Rcv_InterfaceP;

TEMPLATE_METHOD_CLASSES(modAOS_VC_Rcv_Interface, modAOS_VC_Rcv_InterfaceP);

AOS_PHYSICAL_CHANNEL_GENERATE_METHODS(modAOS_VC_Rcv_InterfaceP);
AOS_MASTER_CHANNEL_GENERATE_METHODS(modAOS_VC_Rcv_InterfaceP);
AOS_VIRTUAL_CHANNEL_GENERATE_METHODS(modAOS_VC_Rcv_InterfaceP);

void modAOS_VC_Rcv_Interface::register_methods(xmlrpc_c::registryPtr& rpcRegistry) {
	ACE_TRACE("modAOS_VC_Rcv_Interface::register_methods");

	TEMPLATE_REGISTER_METHODS(modAOS_VC_Rcv, modAOS_VC_Rcv_Interface);

	AOS_PHYSICAL_CHANNEL_REGISTER_METHODS(modAOS_VC_Rcv);
	AOS_MASTER_CHANNEL_REGISTER_METHODS(modAOS_VC_Rcv);
	AOS_VIRTUAL_CHANNEL_REGISTER_METHODS(modAOS_VC_Rcv);

}

} // namespace nAOS_VC_Rcv
