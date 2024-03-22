import argparse
from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker
from My_Base import Base, Series, Episode, Producer

parser = argparse.ArgumentParser(description='Series database')
subparsers = parser.add_subparsers(dest='tables')

series_parser = subparsers.add_parser('series')
series_parser.add_argument('--add', action='store_true')
series_parser.add_argument('--print', action='store_true')
series_parser.add_argument('--name')
series_parser.add_argument('--release_year', type=int)
series_parser.add_argument('--producer')
series_parser.add_argument('--episodes', type=int)

episode_parser = subparsers.add_parser('episode')
episode_parser.add_argument('--add', action='store_true')
episode_parser.add_argument('--print', action='store_true')
episode_parser.add_argument('--number', type=int)
episode_parser.add_argument('--name')
episode_parser.add_argument('--series')

producer_parser = subparsers.add_parser('producer')
producer_parser.add_argument('--add', action='store_true')
producer_parser.add_argument('--print', action='store_true')
producer_parser.add_argument('--id', type=int)
producer_parser.add_argument('--name')
producer_parser.add_argument('--age', type=int)
producer_parser.add_argument('--series')

args = parser.parse_args()

engine = create_engine('sqlite:///base1.db', echo=False)
Base.metadata.create_all(engine)

Session = sessionmaker(bind=engine)
session = Session()

if args.add:
    if args.tables == 'series':
        if args.name and args.release_year and args.producer and args.episodes:
            series = Series(
                name=args.name,
                release_year=args.release_year,
                producer=args.producer,
            )
            session.add(series)
            print(f"Added series: {args.name}")
        else:
            print('All attributes (name, release_year, producer, episodes) are required to add a new series.')

    elif args.tables == 'episode':
        if args.number and args.name:
            episode = Episode(
                number=args.number,
                name=args.name,
            )
            session.add(episode)
            print(f"Added episode: {args.name}")
        else:
            print('Number and name attributes are required to add a new episode.')

    elif args.tables == 'producer':
        if args.name and args.age:
            producer = Producer(
                name=args.name,
                age=args.age,
            )
            session.add(producer)
            print(f"Added producer: {args.name}")
        else:
            print('Name and age attributes are required to add a new producer.')

session.commit()
