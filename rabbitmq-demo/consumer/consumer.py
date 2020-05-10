#!/usr/bin/env python3

import pika

HOST = 'mq'

def callback(ch, method, properties, body):
    print("Got: ", body)

# Connect
con = pika.BlockingConnection(pika.ConnectionParameters(HOST))
channel = con.channel()
print('Connected.')

# Create the queue
channel.queue_declare(queue='foo')


# Consume
channel.basic_consume(queue='foo',
                      auto_ack=True,
                      on_message_callback=callback)

print('Waiting...')
channel.start_consuming()
