# chatserver
能狗在nginx tcp负载均衡环境中的集群聊天服务器和客户端源码 基于moudou实现  redis mysql

编译方式
cd build
rm -rf *
cmake ..
make

环境需要
nginx的tcp负载均衡，启动redis，启动mysql，mudou网络库
