#ifndef IPTABLES_H
#define IPTABLES_H


static bool can_access(char *szIp){

	#if 0
	/* PROTECT IP  check ip for access */
	/*
	 *  127.0.0.1
	 */
	if(!strstr(szIp,"192.168.18.")
		&&stricmp(szIp,"127.0.0.1")){
		return false;
	}
	#endif
	return true;
}

#endif
