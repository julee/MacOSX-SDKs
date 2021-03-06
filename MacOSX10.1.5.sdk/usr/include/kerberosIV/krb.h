/*
 * krb-sed.h
 *
 * Copyright 1987, 1988 by the Massachusetts Institute of Technology. 
 *
 * For copying and distribution information, please see the file
 * <mit-copyright.h>. 
 *
 * External defintions for the Kerberos library.  Internal definitions
 * (visible to Kerberos library source files) are in kerberos.h.
 */

/* Only one time, please */
#ifndef	KRB_H
#define KRB_H

/* Kerberos 4 Error Codes: */
#define KSUCCESS                                 0
#define KFAILURE                                 255

#define KRB_NEVERDATE (0xFFFFFFFFUL)

/* Error codes returned from the KDC */
#define		KDC_OK			0	/* Request OK */
#define		KDC_NAME_EXP	1	/* Principal expired */
#define		KDC_SERVICE_EXP	2	/* Service expired */
#define		KDC_AUTH_EXP	3	/* Auth expired */
#define		KDC_PKT_VER	4	/* Protocol version unknown */
#define		KDC_P_MKEY_VER	5	/* Wrong master key version */
#define		KDC_S_MKEY_VER 	6	/* Wrong master key version */
#define		KDC_BYTE_ORDER	7	/* Byte order unknown */
#define		KDC_PR_UNKNOWN	8	/* Principal unknown */
#define		KDC_PR_N_UNIQUE 9	/* Principal not unique */
#define		KDC_NULL_KEY   10	/* Principal has null key */
#define		KDC_GEN_ERR    20	/* Generic error from KDC */


/* Values returned by get_credentials */
#define		GC_OK			0	/* Retrieve OK */
#define		RET_OK			0	/* Retrieve OK */
#define		GC_TKFIL       21	/* Can't read ticket file */
#define		RET_TKFIL      21	/* Can't read ticket file */
#define		GC_NOTKT       22	/* Can't find ticket or TGT */
#define		RET_NOTKT      22	/* Can't find ticket or TGT */


/* Values returned by mk_ap_req	 */
#define		MK_AP_OK		0	/* Success */
#define		MK_AP_TGTEXP   26	/* TGT Expired */

/* Values returned by rd_ap_req */
#define		RD_AP_OK		0	/* Request authentic */
#define		RD_AP_UNDEC    31	/* Can't decode authenticator */
#define		RD_AP_EXP      32	/* Ticket expired */
#define		RD_AP_NYV      33	/* Ticket not yet valid */
#define		RD_AP_REPEAT   34	/* Repeated request */
#define		RD_AP_NOT_US   35	/* The ticket isn't for us */
#define		RD_AP_INCON    36	/* Request is inconsistent */
#define		RD_AP_TIME     37	/* delta_t too big */
#define		RD_AP_BADD     38	/* Incorrect net address */
#define		RD_AP_VERSION  39	/* protocol version mismatch */
#define		RD_AP_MSG_TYPE 40	/* invalid msg type */
#define		RD_AP_MODIFIED 41	/* message stream modified */
#define		RD_AP_ORDER    42	/* message out of order */
#define		RD_AP_UNAUTHOR 43	/* unauthorized request */

/* Values returned by get_pw_tkt */
#define		GT_PW_OK		0	/* Got password changing tkt */
#define		GT_PW_NULL     51	/* Current PW is null */
#define		GT_PW_BADPW    52	/* Incorrect current password */
#define		GT_PW_PROT     53	/* Protocol Error */
#define		GT_PW_KDCERR   54	/* Error returned by KDC */
#define		GT_PW_NULLTKT  55	/* Null tkt returned by KDC */


/* Values returned by send_to_kdc */
#define		SKDC_OK			0	/* Response received */
#define		SKDC_RETRY     56	/* Retry count exceeded */
#define		SKDC_CANT      57	/* Can't send request */

/*
 * Values returned by get_in_tkt
 * (can also return SKDC_* and KDC errors)
 */

#define		INTK_OK			0	/* Ticket obtained */
#define		INTK_PW_NULL   51	/* Current PW is null */
#define		INTK_W_NOTALL  61	/* Not ALL tickets returned */
#define		INTK_BADPW     62	/* Incorrect password */
#define		INTK_PROT      63	/* Protocol Error */
#define		INTK_ERR       70	/* Other error */

/* Values returned by get_adtkt */
#define         AD_OK      0	/* Ticket Obtained */
#define         AD_NOTGT   71	/* Don't have tgt */

/* Error codes returned by ticket file utilities */
#define		NO_TKT_FIL		76	/* No ticket file found */
#define		TKT_FIL_ACC		77	/* Couldn't access tkt file */
#define		TKT_FIL_LCK		78	/* Couldn't lock ticket file */
#define		TKT_FIL_FMT		79	/* Bad ticket file format */
#define		TKT_FIL_INI		80	/* tf_init not called first */

/* Error code returned by kparse_name */
#define		KNAME_FMT		81	/* Bad Kerberos name format */

/* Error code returned by krb_mk_safe */
#define		SAFE_PRIV_ERROR	-1	/* syscall error */

#define KADM_RCSID                               (-1783126272)
#define KADM_NO_REALM                            (-1783126271)
#define KADM_NO_CRED                             (-1783126270)
#define KADM_BAD_KEY                             (-1783126269)
#define KADM_NO_ENCRYPT                          (-1783126268)
#define KADM_NO_AUTH                             (-1783126267)
#define KADM_WRONG_REALM                         (-1783126266)
#define KADM_NO_ROOM                             (-1783126265)
#define KADM_BAD_VER                             (-1783126264)
#define KADM_BAD_CHK                             (-1783126263)
#define KADM_NO_READ                             (-1783126262)
#define KADM_NO_OPCODE                           (-1783126261)
#define KADM_NO_HOST                             (-1783126260)
#define KADM_UNK_HOST                            (-1783126259)
#define KADM_NO_SERV                             (-1783126258)
#define KADM_NO_SOCK                             (-1783126257)
#define KADM_NO_CONN                             (-1783126256)
#define KADM_NO_HERE                             (-1783126255)
#define KADM_NO_MAST                             (-1783126254)
#define KADM_NO_VERI                             (-1783126253)
#define KADM_INUSE                               (-1783126252)
#define KADM_UK_SERROR                           (-1783126251)
#define KADM_UK_RERROR                           (-1783126250)
#define KADM_UNAUTH                              (-1783126249)
#define KADM_DATA                                (-1783126248)
#define KADM_NOENTRY                             (-1783126247)
#define KADM_NOMEM                               (-1783126246)
#define KADM_NO_HOSTNAME                         (-1783126245)
#define KADM_NO_BIND                             (-1783126244)
#define KADM_LENGTH_ERROR                        (-1783126243)
#define KADM_ILL_WILDCARD                        (-1783126242)
#define KADM_DB_INUSE                            (-1783126241)
#define KADM_INSECURE_PW                         (-1783126240)
#define KADM_PW_MISMATCH                         (-1783126239)
#define KADM_NOT_SERV_PRINC                      (-1783126238)

#ifndef rez /* This stuff will confuse rez */

#if defined(macintosh) || (defined(__MACH__) && defined(__APPLE__))
	#include <KerberosSupport/KerberosSupport.h>
#endif

#if TARGET_OS_MAC
    #include <kerberosIV/des.h>
    #include <profile.h>
#else
    #include <des.h>
    #include <profile.h>
#endif

#if TARGET_API_MAC_OSX
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
#else
    struct sockaddr_in;
#endif

#if TARGET_API_MAC_OSX && TARGET_API_MAC_CARBON
    #include <CoreServices/CoreServices.h>
#elif TARGET_API_MAC_OS8 || TARGET_API_MAC_CARBON
    #include <Files.h>
#else
	#error "Unknown OS"
#endif

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#if PRAGMA_IMPORT
#	pragma import on
#endif

#if PRAGMA_STRUCT_ALIGN
	#pragma options align=mac68k
#elif PRAGMA_STRUCT_PACKPUSH
	#pragma pack(push, 2)
#elif PRAGMA_STRUCT_PACK
	#pragma pack(2)
#endif

#if PRAGMA_ENUM_ALWAYSINT
	#pragma enumsalwaysint on
#endif

#if TARGET_CPU_68K
	#pragma fourbyteints on
#endif 

#if !defined(PROTOTYPE)
#if defined(__STDC__) || defined(__cplusplus) || defined(_MSDOS) || defined(_WIN32)
#define PROTOTYPE(x) x
#else
#define PROTOTYPE(x) ()
#endif
#endif

#define	INTERFACE	/* No special declaration?? FIXME. */
#define FAR

/* Sizes of types we need */
#ifndef KRB_INT32
#define KRB_INT32 SInt32
#endif
#ifndef KRB_UINT32
#define KRB_UINT32 UInt32
#endif

/* The maximum sizes for aname, realm, sname, and instance +1 */
#define 	ANAME_SZ	40
#define		REALM_SZ	40
#define		SNAME_SZ	40
#define		INST_SZ		40
/* include space for '.' and '@' */
#define		MAX_K_NAME_SZ	(ANAME_SZ + INST_SZ + REALM_SZ + 2)
#define		KKEY_SZ		100
#define		VERSION_SZ	1
#define		MSG_TYPE_SZ	1
#define		DATE_SZ		26	/* RTI date output */

#ifndef DEFAULT_TKT_LIFE			 /* allow compile-time override */
#define		DEFAULT_TKT_LIFE	120 /* default lifetime 10 hrs */
#endif

#define		TICKET_GRANTING_TICKET	"krbtgt"

/* Definition of text structure used to pass text around */
#define		MAX_KTXT_LEN	1250

struct ktext {
    int     length;						/* Length of the text */
    unsigned char dat[MAX_KTXT_LEN];	/* The data itself */
    unsigned long mbz;					/* zero to catch runaway strings */
};

typedef struct ktext *KTEXT;
typedef struct ktext KTEXT_ST;


/* Definitions for send_to_kdc */
#define	CLIENT_KRB_TIMEOUT	4	/* time between retries */
#define CLIENT_KRB_RETRY	5	/* retry this many times */
#define	CLIENT_KRB_BUFLEN	512	/* max unfragmented packet */

/* Definitions for ticket file utilities */
#define	R_TKT_FIL	0
#define	W_TKT_FIL	1

/* Structure definition for rd_ap_req */

struct auth_dat {
    unsigned char k_flags;		/* Flags from ticket */
    char    pname[ANAME_SZ];	/* Principal's name */
    char    pinst[INST_SZ];		/* His Instance */
    char    prealm[REALM_SZ];	/* His Realm */
    KRB_UINT32 checksum;		/* Data checksum (opt) */
    C_Block session;			/* Session Key */
    int     life;				/* Life of ticket */
    KRB_UINT32 time_sec;		/* Time ticket issued */
    KRB_UINT32 address;			/* Address in ticket */
    KTEXT_ST reply;				/* Auth reply (opt) */
};

typedef struct auth_dat AUTH_DAT;

/* Structure definition for credentials returned by get_cred */

struct credentials {
    char    service[ANAME_SZ];	/* Service name */
    char    instance[INST_SZ];	/* Instance */
    char    realm[REALM_SZ];	/* Auth domain */
    C_Block session;			/* Session key */
    int     lifetime;			/* Lifetime */
    int     kvno;				/* Key version number */
    KTEXT_ST ticket_st;			/* The ticket itself */
    long    issue_date;			/* The issue time */
    char    pname[ANAME_SZ];	/* Principal's name */
    char    pinst[INST_SZ];		/* Principal's instance */
    KRB_UINT32 address;			/* Address in ticket */
    KRB_UINT32 stk_type;		/* string_to_key function needed */
};

typedef struct credentials CREDENTIALS;

/* Structure definition for rd_private_msg and rd_safe_msg */

struct msg_dat {
    unsigned char *app_data;	/* pointer to appl data */
    KRB_UINT32 app_length; 		/* length of appl data */
    unsigned long hash;			/* hash to lookup replay */
    int     swap;				/* swap bytes? */
    KRB_INT32    time_sec;		/* msg timestamp seconds */
    unsigned char time_5ms;		/* msg timestamp 5ms units */
};

typedef struct msg_dat MSG_DAT;


/* Location of default ticket file for save_cred and get_cred */
#ifndef	TKT_FILE
#define	TKT_FILE				tkt_string()
#endif /* TKT_FILE */

/* Defines for krb_sendauth, krb_mk_auth, krb_check_auth, and krb_recvauth */

#define	KOPT_DONT_MK_REQ 0x00000001 /* don't call krb_mk_req */
#define	KOPT_DO_MUTUAL   0x00000002 /* do mutual auth */

#define	KOPT_DONT_CANON  0x00000004 /*
				     * don't canonicalize inst as
				     * a hostname
				     */

#define	KRB_SENDAUTH_VLEN 8	    /* length for version strings */

#ifdef ATHENA_COMPAT
#define	KOPT_DO_OLDSTYLE 0x00000008 /* use the old-style protocol */
#endif /* ATHENA_COMPAT */

/* Constants for KerberosProfileLib */
#define		REALMS_V4_PROF_REALMS_SECTION		"v4 realms"
#define		REALMS_V4_PROF_KDC					"kdc"
#define		REALMS_V4_PROF_ADMIN_KDC			"admin_server"
#define		REALMS_V4_PROF_KPASSWD_KDC			"kpasswd_server"
#define		REALMS_V4_PROF_DOMAIN_SECTION		"v4 domain_realm"
#define		REALMS_V4_PROF_LIBDEFAULTS_SECTION	"libdefaults"
#define		REALMS_V4_PROF_LOCAL_REALM			"default_realm"
#define		REALMS_V4_PROF_STK					"string_to_key_type"
#define		REALMS_V4_MIT_STK					"mit_string_to_key"
#define		REALMS_V4_AFS_STK					"afs_string_to_key"
#define		REALMS_V4_COLUMBIA_STK				"columbia_string_to_key"
#define		REALMS_V4_DEFAULT_REALM				"default_realm"
#define		REALMS_V4_NO_ADDRESSES				"noaddresses"

/* Define a couple of function types including parameters.  These
   are needed on MS-Windows to convert arguments of the function pointers
   to the proper types during calls.  */
typedef int (*key_proc_type) PROTOTYPE ((char *, char *, char *,
					     char *, C_Block));
typedef int (*decrypt_tkt_type) PROTOTYPE ((char *, char *, char *, char *,
				     key_proc_type, KTEXT *));
#define	KEY_PROC_TYPE_DEFINED
#define	DECRYPT_TKT_TYPE_DEFINED


/******************************************/
/*** EXPORTED FUNTIONS (by source file) ***/
/******************************************/

/* change_password.c */
extern int INTERFACE
krb_change_password PROTOTYPE ((char *, char *, char *, char *, char *));

/* decomp_tkt.c */ 
extern int INTERFACE
decomp_ticket PROTOTYPE ((KTEXT, unsigned char *, char *, char *, char *, KRB_UINT32 *, C_Block,
	int *, KRB_UINT32 *, char *, char *, C_Block, Key_schedule));

/* err_txt.c */
extern const char * INTERFACE
krb_get_err_text PROTOTYPE ((int));

/* g_ad_tkt.c */
extern int INTERFACE
get_ad_tkt PROTOTYPE ((char *service, char *sinstance, char *realm, int lifetime));

/* g_in_tkt.c */
extern int INTERFACE
krb_get_in_tkt PROTOTYPE ((char *, char *, char *, char *, char *, int,
			   key_proc_type, decrypt_tkt_type, char *arg));

extern int INTERFACE
krb_get_in_tkt_creds PROTOTYPE ((char *, char *, char *, char *, char *, int, 
		key_proc_type, decrypt_tkt_type, char *, CREDENTIALS *));

/* g_phost.c */
extern char * INTERFACE
krb_get_phost PROTOTYPE ((char  *));

/* g_pw_in_tkt.c */
extern int INTERFACE
krb_get_pw_in_tkt PROTOTYPE ((char *, char *, char *,
		char *, char *, int, char *));

extern int INTERFACE
krb_get_pw_in_tkt_creds PROTOTYPE ((char *, char *, char *, 
	char *, char *, int, char *, CREDENTIALS *));

/* g_pw_tkt.c */
extern int INTERFACE
get_pw_tkt PROTOTYPE ((char *, char *, char *,
	char *));

/* g_svc_in_tkt.c */
extern int INTERFACE
krb_get_svc_in_tkt PROTOTYPE ((char *, char *, char *,
	char *, char *, int, char *));

#if TARGET_OS_MAC
extern int INTERFACE
FSp_krb_get_svc_in_tkt PROTOTYPE ((char *, char *, char *, 
	char *, char *, int, const FSSpec *));
#endif

/* g_tkt_svc.c */
extern int INTERFACE
krb_get_ticket_for_service PROTOTYPE ((char *, char *,
	KRB_UINT32 *, int, des_cblock, Key_schedule,
	char *, int));
 
/* kname_parse.c */
int k_isname (const char *s);
int k_isinst (const char *s);
int k_isrealm (const char *s);
int kname_parse (char *, char *, char *, const char *);
int kname_unparse (char *, const char *, const char *, const char *);

/* lifetime.c */
KRB5_DLLIMP UInt32 KRB5_CALLCONV krb_life_to_time
	PROTOTYPE((UInt32 start, int life));
KRB5_DLLIMP int KRB5_CALLCONV krb_time_to_life
	PROTOTYPE((UInt32 start, UInt32 end));

/* mk_auth.c */
extern int INTERFACE
krb_check_auth PROTOTYPE ((KTEXT, KRB_UINT32, MSG_DAT *,
		C_Block FAR, Key_schedule, struct sockaddr_in *,
		struct sockaddr_in *));

extern int INTERFACE
krb_mk_auth PROTOTYPE ((long, KTEXT, char *, char *, char *, 
		KRB_UINT32, char *, KTEXT));

/* mk_err.c */
extern long INTERFACE
krb_mk_err PROTOTYPE ((unsigned char *, KRB_INT32, char *));

/* mk_priv.c */
extern long INTERFACE
krb_mk_priv PROTOTYPE ((unsigned char *, unsigned char *, KRB_UINT32, 
	Key_schedule FAR, C_Block, struct sockaddr_in *, struct sockaddr_in *));

/* mk_req.c */
extern int INTERFACE
krb_mk_req PROTOTYPE ((KTEXT, char *, char *, char *, KRB_INT32));

extern int INTERFACE
krb_mk_req_creds PROTOTYPE ((register KTEXT, CREDENTIALS *, KRB_INT32));

int
krb_set_lifetime(int newval);

/* mk_safe.c */
extern long INTERFACE
krb_mk_safe PROTOTYPE ((unsigned char *, unsigned char *,
	KRB_UINT32, C_Block, struct sockaddr_in *,
	struct sockaddr_in *));

/* rd_err.c */
extern int INTERFACE
krb_rd_err PROTOTYPE ((unsigned char *, unsigned long, long *, MSG_DAT *));

/* rd_priv.c */
extern long INTERFACE
krb_rd_priv PROTOTYPE ((unsigned char *, KRB_UINT32,
	Key_schedule FAR, C_Block, struct sockaddr_in *,
	struct sockaddr_in *, MSG_DAT *));

/* rd_req.c */
extern int INTERFACE
krb_rd_req PROTOTYPE ((KTEXT, char *, char *,
	KRB_UINT32, AUTH_DAT *, char *));

/* rd_req_int.c */
extern int INTERFACE
krb_rd_req_int PROTOTYPE ((KTEXT, char *, char *,
	KRB_UINT32, AUTH_DAT *, C_Block));

/* rd_svc_key.c */
extern int INTERFACE
read_service_key PROTOTYPE ((char *, char *, char *, int, char *, char *));

#if TARGET_OS_MAC
extern int INTERFACE
FSp_read_service_key PROTOTYPE ((char *, char *, char *, int, const FSSpec*, char *));
#endif

/* rd_safe.c */
extern long INTERFACE
krb_rd_safe PROTOTYPE ((unsigned char *, KRB_UINT32,
	C_Block, struct sockaddr_in *, struct sockaddr_in *, MSG_DAT *));

/* recvauth.c */
extern int INTERFACE
krb_recvauth PROTOTYPE ((long, int, KTEXT, char *, char *,
	struct sockaddr_in *, struct sockaddr_in *,
	AUTH_DAT *, char *, Key_schedule FAR, char *));

/* sendauth.c */
extern int INTERFACE 
krb_sendauth PROTOTYPE ((long, int, KTEXT, char *, char *, char *, 
	KRB_UINT32, MSG_DAT *, CREDENTIALS *, Key_schedule, 
	struct sockaddr_in *, struct sockaddr_in *, char *));

/* CCache-glue.c */
extern int INTERFACE
krb_get_tf_realm PROTOTYPE ((const char *, char *));

extern int INTERFACE
krb_get_tf_fullname PROTOTYPE ((char *, char *, char *,
	char *));

extern int INTERFACE
krb_get_cred PROTOTYPE ((char *, char *, char *, CREDENTIALS *));

extern const char * INTERFACE 
tkt_string PROTOTYPE ((void));

extern void INTERFACE
krb_set_tkt_string PROTOTYPE ((const char *));

extern int INTERFACE
dest_tkt PROTOTYPE ((void));

#if TARGET_OS_MAC
/* The following functions are not part of the standard Kerberos v4 API. 
 * They were created for Mac implementation, and used by admin tools 
 * such as CNS-Config. */
extern int INTERFACE 
krb_get_num_cred PROTOTYPE ((void));

extern int INTERFACE
krb_get_nth_cred PROTOTYPE ((char *, char *, char *, int));

extern int INTERFACE
krb_delete_cred PROTOTYPE ((char *, char *,char *));

extern int INTERFACE
dest_all_tkts PROTOTYPE ((void));

#endif /* TARGET_OS_MAC */

/* RealmConfig-glue.c */
extern int INTERFACE
krb_get_profile PROTOTYPE ((profile_t* profile));

extern int INTERFACE
krb_get_lrealm PROTOTYPE ((char *, int));

extern int INTERFACE
krb_get_admhst PROTOTYPE ((char *, char *, int));

extern int INTERFACE
krb_get_krbhst PROTOTYPE ((char *, const char *, int));

extern char * INTERFACE
krb_realmofhost PROTOTYPE ((char *));

extern int INTERFACE
put_svc_key PROTOTYPE ((char *, char *, char *, char *, int, char *));

#if TARGET_API_MAC_CARBON || TARGET_API_MAC_OS8
extern int INTERFACE
FSp_put_svc_key PROTOTYPE ((const FSSpec *, char *, char *, char *, int, char *));
#endif


#if TARGET_CPU_68K
	#pragma fourbyteints reset
#endif 

#if PRAGMA_ENUM_ALWAYSINT
	#pragma enumsalwaysint reset
#endif

#if PRAGMA_STRUCT_ALIGN
	#pragma options align=reset
#elif PRAGMA_STRUCT_PACKPUSH
	#pragma pack(pop)
#elif PRAGMA_STRUCT_PACK
	#pragma pack()
#endif

#if PRAGMA_IMPORT
#	pragma import reset
#endif

#ifdef __cplusplus
}
#endif

#endif  /* !rez */
#endif	/* KRB_H */
