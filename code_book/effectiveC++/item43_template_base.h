#include <iostream>

template<typename Company>
class MsgSender
{
public:
  void sendClear() {
    Company c;
    std::cout << "MsgSender::sendClear()" << std::endl;
  }
  void sendSeceret() {}
};

template <class Company>
class LoggingMsgSender : public MsgSender<Company> {
  using MsgSender<Company>::sendClear;
public:
  void sendClearMsg() {
    sendClear(); //has to be using
  }
};

