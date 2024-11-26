#include <zmq.hpp>
#include <string>
#include <iostream>

int main() {
    zmq::context_t context(1); // ZeroMQ context oluştur
    zmq::socket_t socket(context, zmq::socket_type::req); // İstemci soketi
    socket.connect("tcp://localhost:5555"); // Sunucuya bağlan

    std::string message = "as";
    zmq::message_t request(message.size());
    memcpy(request.data(), message.data(), message.size());
    socket.send(request, zmq::send_flags::none);

    zmq::message_t reply;
    socket.recv(reply, zmq::recv_flags::none); // Yanıtı al
    std::cout << "Sunucudan Gelen Cevap: " << reply.to_string() << std::endl;

    return 0;
}

