#!/usr/bin/env python3

import pika

HOST = 'mq'

# Connect
con = pika.BlockingConnection(pika.ConnectionParameters(HOST))
channel = con.channel()
print('Connected.')

# Create a queue
channel.queue_declare(queue='foo')

# Say hello
channel.basic_publish(exchange='',
                      routing_key='foo',
                      body='Hello World!')

print('Done.')

channel.close()
