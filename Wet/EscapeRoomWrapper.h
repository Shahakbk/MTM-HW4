//
// Created by adire on 28-Jun-17.
//

#ifndef PARTONE_ESCAPEROOMWRAPPER_H
#define PARTONE_ESCAPEROOMWRAPPER_H


#include <string>
#include <iostream>
#include <vector>

#include "EscapeRoom.h"
#include "Enigma.h"

using std::vector;

namespace mtm{
    namespace escaperoom {

        class EscapeRoomWrapper{

            EscapeRoom escape_room;
            vector<Enigma> enigmas;

        public:
            // Constructs a new Escape Room with the specified data.
            //
            // @param name : the name of the escape room.
            // @param escapeTime : the maximal escape time allowed in the room.
            // @param level : the level of the escape room.
            // @param maxParticipants: the maximal participants allowed in the room.
            // The rest of the room's data is initialized as described in the exercise sheet.
            // @throws EscapeRoomMemoryProblemException in case of creation failure.
            EscapeRoomWrapper(char* name, const int& escapeTime, const int& level, const int& maxParticipants);

            // Constructs a new Escape Room with the specified data.
            //
            // @param name : the name of the enigma.
            // @param level : the level of the escape room.
            // The rest of the room's data is initialized as described in the exercise sheet.
            // @throws EscapeRoomMemoryProblemException in case of creation failure.
            EscapeRoomWrapper(char* name, const int& level);

            //copy constructor
            //
            //@param room : the room to be copied.
            //@throws EscapeRoomMemoryProblemException in case of creation failure.
            EscapeRoomWrapper(const EscapeRoomWrapper& room);

            /**
             * adds an enigma to the room
             * @param enigma - the enigma to add into the enigmas vector within
             * the room
             */
            void addEnigma(const Enigma& enigma);

            /**
             * removes an enigma from the room
             * @param enigma - the enigma to find in the room and remove
             */
            void removeEnigma(const Enigma& enigma);

            /**
             * find the hardest enigma in the room
             * @return - a copy of the hardest enigma (the first one in the
             * vector if there are a few)
             */
            Enigma getHardestEnigma();

            /**
             * returns all of the enigmas in the room
             * @return - a copy of the enigmas vector of the room
             */
            vector<Enigma>& getAllEnigmas();

            /**
             * adds an element to the given enigma in the room
             * @param enigma - the enigma to add the element to
             * @param element - the element to add to the enigma
             */
            void addElement(const Enigma& enigma, const string& element);

            /**
             * removes an element from a specific enigma in the room
             * @param enigma - the enigma to remove the element from
             * @param element - the element to remove from the enigma
             */
            void removeElement(const Enigma &enigma, const string& element);

            //assignment operator
            //
            //@param room : the room to be assigned.
            EscapeRoomWrapper& operator=(const EscapeRoomWrapper& room);

            // Comparison operators for Escape Rooms. rooms are compared as described in
            // the exercise sheet.
            //
            // @param room : the right-hand side operand.
            bool operator==(const EscapeRoomWrapper& room) const;
            bool operator!=(const EscapeRoomWrapper& room) const;
            bool operator<(const EscapeRoomWrapper& room) const;
            bool operator>(const EscapeRoomWrapper& room) const;

            bool operator<=(const EscapeRoomWrapper& room) const = delete;
            bool operator>=(const EscapeRoomWrapper& room) const = delete;

            // return the level of the Escape Room.
            //
            int level() const;

            // the method changes the rate according to the rate given.
            //
            // @param newRate : the new rate accepted to the room.
            //@throws EscapeRoomIllegalRateException in case of illegal rate parameter.
            void rate(const int& newRate);

            // Destructor for EscapeRoomWrapper
            virtual ~EscapeRoomWrapper();

            // Prints the data of the Room in the following format:
            //
            //     "<name> (<maxTime>/<level>/<maxParticipants>)"
            //
            // @param output : the output stream to which the data is printed.
            // @param room : the room whose data is printed.
            friend std::ostream& operator<<(std::ostream& output, const EscapeRoomWrapper& room);

            //Function returns the name of the EscapeRoom.
            //
            std::string getName() const;

            //Function returns the rate of the EscapeRoom.
            //
            double getRate() const;

            //Function returns the maximum escape time of the EscapeRoom.
            //
            int getMaxTime() const;

            //Function returns the number of participants allowed in the EscapeRoom.
            //
            int getMaxParticipants() const;

            /**
             * returns a ptr to the room according to its type
             */
            virtual EscapeRoomWrapper* clone() const;

        protected:

            /**
             * a virtual function that will be called from within the <<
             * operator, since '<<' is a friend function and not a method and
             * thus cannot be virtual and overrode.
             * it is declared as 'protected' hence it can be inherited
             */
            virtual void print(std::ostream& output) const;
        };

        std::ostream& operator<<(std::ostream& output, const EscapeRoomWrapper& room);
    } // end of namespace eascaperoom
} // end of namespace mtm

#endif //PARTONE_ESCAPEROOMWRAPPER_H
