# 手动指定 MySQL 库路径
link_directories(/usr/lib64/mysql)

# 定义了一个名为 SRC_LIST 的可执行文件，并将当前目录下的所有源文件添加到该可执行文件中。
aux_source_directory(. SRC_LIST)
aux_source_directory(./db DB_LIST)
aux_source_directory(./model MODEL_LIST)
aux_source_directory(./redis REDIS_LIST)

# 指定生成可执行文件
add_executable(ChatServer ${SRC_LIST} ${DB_LIST} ${MODEL_LIST} ${REDIS_LIST})

# 指定可执行文件链接时需要的库文件。
target_link_libraries(ChatServer muduo_net muduo_base mysqlclient hiredis pthread)