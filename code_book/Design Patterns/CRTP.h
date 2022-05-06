#include <iostream>
/// https://liam.page/2016/11/26/Introduction-to-CRTP-in-Cpp/

template<typename Sender>
class MsgSender
{
public:
  void sendClear() {
    static_cast<Sender*>(this)->sendClear();
  }
  void sendSeceret() {}
};

class LoggingMsgSender : public MsgSender<LoggingMsgSender> {
public:
  void sendClear() {
    std::cout << "LoggingMsgSender::sendClear" << std::endl;
  }
};

class SecretMsgSender : public MsgSender<SecretMsgSender> {
public:
  void sendClear() {
    std::cout << "SecretMsgSender::sendClear" << std::endl;
  }
};

