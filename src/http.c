/*
 * http.c
 *
 *  Created on: 08.02.2018.
 *      Author: srkos
 */

#include <stdio.h>
//#define CURL_STATICLIB
#include <curl/curl.h>

#include "http.h"

size_t CB_http_get_response(void *ptr, size_t size, size_t nmemb, void *stream)
{
	const char *ok_str = SUCCESSFUL_RESPONSE;
	int ok_str_len;

	ok_str_len = strlen(ok_str);

	int *ret_val = (int *) stream;

	*ret_val = strncmp(ptr, ok_str, ok_str_len);

	return nmemb;
}

int http_ack(char *twr_ack_url, char *post_fields)
{
	CURL *curl;
	CURLcode res;
	int r = 1;

	curl_global_init(CURL_GLOBAL_ALL);

	curl = curl_easy_init();
	if (curl)
	{
		curl_easy_setopt(curl, CURLOPT_URL, twr_ack_url);

		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post_fields);

		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, CB_http_get_response);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &r);

		res = curl_easy_perform(curl);
		if (res != CURLE_OK)
			fprintf(stderr, "curl_easy_perform() failed: %s\n",
					curl_easy_strerror(res));

		curl_easy_cleanup(curl);
	}
	curl_global_cleanup();

	return r;
}
