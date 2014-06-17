#ifndef ICOMET_SERVER_H
#define ICOMET_SERVER_H

#include "../build.h"
#include <vector>
#include <map>
#include <list>
#include "../libevent/evhttp.h"
#include "../libevent/event2/http.h"
#include "../util/list.h"
#include "channel.h"
#include "subscriber.h"
#include "presence.h"

#define DEFAULT_JSONP_CALLBACK	"icomet_cb"
#define CHANNEL_CHECK_INTERVAL	1

class Server
{
private:
	// mapping cname(channel_name) to channel
	std::map<std::string, Channel *> cname_channels;
	
	int subscribers;
	LinkedList<Channel *> used_channels;
	LinkedList<Channel *> free_channels;

	Channel* get_channel_by_name(const std::string &name);
	Channel* new_channel(const std::string &cname);
	void free_channel(Channel *channel);

	LinkedList<PresenceSubscriber *> psubs;

	void add_presence(PresenceType type, const std::string &cname);
	//void flush_presence();

	int sub(struct evhttp_request *req, Subscriber::Type sub_type);
public:
	enum{
		AUTH_NONE  = 0,
		AUTH_TOKEN = 1
	};

	int auth;
	
	Server();
	~Server();
	
	int check_timeout();
	
	int sub_end(Subscriber *sub);
	int ping(struct evhttp_request *req);
	int poll(struct evhttp_request *req);
	int iframe(struct evhttp_request *req);
	int stream(struct evhttp_request *req);

	int pub(struct evhttp_request *req, bool encoded);
	int sign(struct evhttp_request *req);
	int close(struct evhttp_request *req);
	int clear(struct evhttp_request *req);
	int info(struct evhttp_request *req);
	int check(struct evhttp_request *req);
	
	int psub(struct evhttp_request *req);
	int psub_end(PresenceSubscriber *psub);
	
};

#endif
