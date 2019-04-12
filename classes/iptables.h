#ifndef IPTABLES_H
#define IPTABLES_H


static bool can_access(char *szIp){

	#ifndef WIN32
	/* PROTECT IP  check ip for access */
	/*
	 *	61.130.182.122
	 *	120.199.11.146
	 *  127.0.0.1
	 */
	if(stricmp(szIp,"61.130.182.122")
		&&stricmp(szIp,"120.199.11.146")
		&&!strstr(szIp,"192.168.18.")
		&&stricmp(szIp,"127.0.0.1")){
		return false;
	}
	#endif
	return true;
}

#endif
