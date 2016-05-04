/*
    This file is part of telegram-cli.

    Telegram-cli is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    Telegram-cli is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this telegram-cli.  If not, see <http://www.gnu.org/licenses/>.

    Copyright Vitaly Valtman 2013-2015
*/
#ifndef __INTERFACE_H__
#define __INTERFACE_H__

#include "tdc/tdlib-c-bindings.h"

union tdl_chat;

#define COLOR_RED "\033[0;31m"
#define COLOR_REDB "\033[1;31m"
#define COLOR_NORMAL "\033[0m"
#define COLOR_GREEN "\033[32;1m"
#define COLOR_GREY "\033[37;1m"
#define COLOR_YELLOW "\033[33;1m"
#define COLOR_BLUE "\033[34;1m"
#define COLOR_MAGENTA "\033[35;1m"
#define COLOR_CYAN "\033[36;1m"
#define COLOR_LCYAN "\033[0;36m"

#define COLOR_INVERSE "\033[7m"

char *get_default_prompt (void);
char *complete_none (const char *text, int state);
char **complete_text (char *text, int start, int end);
void interpreter (char *line);
struct in_command;
void interpreter_ex (struct in_command *cmd);

void rprintf (const char *format, ...) __attribute__ ((format (printf, 1, 2)));
void logprintf (const char *format, ...) __attribute__ ((format (printf, 1, 2)));

#define vlogprintf(v,...) \
  do { \
    if (TLS->verbosity >= (v)) {\
      logprintf (__VA_ARGS__);\
    }\
  } while (0);\


//void hexdump (int *in_ptr, int *in_end);

struct bufferevent;
struct in_ev {
  struct bufferevent *bev;
  char in_buf[4096];
  ssize_t in_buf_pos;
  int refcnt;
  int error;
  int fd;
};


struct tdl_user;
struct tdl_chat_info;
struct tdl_message;
struct in_ev;
void print_message (struct in_ev *ev, struct tdl_message *M);
void print_user_name (struct in_ev *ev, struct tdl_user *U, int id);
void print_chat_name (struct in_ev *ev, struct tdl_chat_info *C, long long id);
void print_channel_name (struct in_ev *ev, struct tdl_channel *C, int id);
void print_user_status (struct in_ev *ev, struct tdl_user_status *S);
/*void print_chat_name (struct in_ev *ev, tgl_peer_id_t id, tgl_peer_t *C);
void print_channel_name (struct in_ev *ev, tgl_peer_id_t id, tgl_peer_t *C);
void print_user_name (struct in_ev *ev, tgl_peer_id_t id, tgl_peer_t *U);
void print_encr_chat_name_full (struct in_ev *ev, tgl_peer_id_t id, tgl_peer_t *C);
void print_encr_chat_name (struct in_ev *ev, tgl_peer_id_t id, tgl_peer_t *C);*/
//void print_media (struct tdl_message_media *M);
//
void pop_color (void);
void push_color (const char *color);
void print_start (void);
void print_end (void);
void print_date_full (struct in_ev *ev, long t);
void print_date (struct in_ev *ev, long t);

void play_sound (void);
void update_prompt (void);
void set_interface_callbacks (void);

struct in_command {
  char *line;
  struct in_ev *ev;
  int refcnt;
  long long query_id;
  struct tdl_chat_info *chat_mode_chat;
};
void in_command_decref (struct in_command *cmd);

//char *print_permanent_msg_id (tdl_message_id_t id);
//char *print_permanent_peer_id (tgl_peer_id_t id);
//tgl_peer_id_t parse_input_peer_id (const char *s, int l, int mask);
//tdl_message_id_t parse_input_msg_id (const char *s, int l);
#endif
