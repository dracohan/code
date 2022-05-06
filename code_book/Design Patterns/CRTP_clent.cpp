#include "CRTP.h"

int main() {
  // LoggingMsgSender lms;
  MsgSender<LoggingMsgSender> *ms = new LoggingMsgSender();
  ms->sendClear();

  MsgSender<SecretMsgSender> *ms1 = new SecretMsgSender();
  ms1->sendClear();
}