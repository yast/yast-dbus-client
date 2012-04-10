/*
 * Copyright (c) 2012 Novell, Inc.
 *
 * All Rights Reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as published
 * by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, contact Novell, Inc.
 *
 * To contact Novell about this file by physical or electronic mail, you may
 * find current contact information at www.novell.com.
 */

/*
 * File:	DbusAgent.h
 *
 * Authors:	Arvin Schnell <aschnell@suse.de>
 */

#ifndef DbusAgent_h
#define DbusAgent_h


#include <dbus/dbus.h>

#include <ycp/YCPValue.h>
#include <scr/SCRAgent.h>


/**
 * @short SCR Agent for DBus commands.
 *
 * aschnell: WARNING: This agent was written in a hurry for exactly one single
 * purpose (acquire global HAL interface lock). Likely use for other commands
 * is not possible but I'm confident the agent can be extended at the
 * sacrifice of changing the API.
 */
class DbusAgent : public SCRAgent
{

public:

    DbusAgent();
    ~DbusAgent();

    /**
     * Read data
     */
    virtual YCPValue Read(const YCPPath& path, const YCPValue& arg = YCPNull(), const YCPValue& opt = YCPNull());

    /**
     * Write data
     */
    virtual YCPBoolean Write(const YCPPath& path, const YCPValue& value,
			     const YCPValue& arg = YCPNull());

    /**
     * Execute a command
     */
    virtual YCPValue Execute(const YCPPath& path, const YCPValue& value = YCPNull(),
			     const YCPValue& arg = YCPNull());

    /**
     * Get a list of all subtrees
     */
    virtual YCPList Dir(const YCPPath& path) { return YCPList(); }

    /**
     * Used for mounting the agent.
     */
    virtual YCPValue otherCommand(const YCPTerm& term);

private:

    void connect(DBusBusType type);
    void disconnect();

    DBusConnection* connection;
    DBusError error;

};


#endif // DbusAgent_h
