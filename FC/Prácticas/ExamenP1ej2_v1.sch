<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan3" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="XLXN_1" />
        <signal name="XLXN_13" />
        <signal name="XLXN_14" />
        <signal name="XLXN_15" />
        <signal name="XLXN_17" />
        <signal name="XLXN_18" />
        <signal name="C" />
        <signal name="A" />
        <signal name="XLXN_22" />
        <signal name="XLXN_23" />
        <signal name="Z" />
        <signal name="B" />
        <port polarity="Input" name="C" />
        <port polarity="Input" name="A" />
        <port polarity="Output" name="Z" />
        <port polarity="Input" name="B" />
        <blockdef name="inv">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="160" y1="-32" y2="-32" x1="224" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="64" y1="0" y2="-64" x1="64" />
            <circle r="16" cx="144" cy="-32" />
        </blockdef>
        <blockdef name="or2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="192" y1="-96" y2="-96" x1="256" />
            <arc ex="192" ey="-96" sx="112" sy="-48" r="88" cx="116" cy="-136" />
            <arc ex="48" ey="-144" sx="48" sy="-48" r="56" cx="16" cy="-96" />
            <line x2="48" y1="-144" y2="-144" x1="112" />
            <arc ex="112" ey="-144" sx="192" sy="-96" r="88" cx="116" cy="-56" />
            <line x2="48" y1="-48" y2="-48" x1="112" />
        </blockdef>
        <blockdef name="and2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="192" y1="-96" y2="-96" x1="256" />
            <arc ex="144" ey="-144" sx="144" sy="-48" r="48" cx="144" cy="-96" />
            <line x2="64" y1="-48" y2="-48" x1="144" />
            <line x2="144" y1="-144" y2="-144" x1="64" />
            <line x2="64" y1="-48" y2="-144" x1="64" />
        </blockdef>
        <block symbolname="and2" name="XLXI_9">
            <blockpin signalname="C" name="I0" />
            <blockpin signalname="A" name="I1" />
            <blockpin signalname="XLXN_22" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_10">
            <blockpin signalname="XLXN_17" name="I0" />
            <blockpin signalname="A" name="I1" />
            <blockpin signalname="XLXN_23" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_11">
            <blockpin signalname="B" name="I" />
            <blockpin signalname="XLXN_17" name="O" />
        </block>
        <block symbolname="or2" name="XLXI_12">
            <blockpin signalname="XLXN_23" name="I0" />
            <blockpin signalname="XLXN_22" name="I1" />
            <blockpin signalname="Z" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="592" y="656" name="XLXI_9" orien="R0" />
        <instance x="592" y="896" name="XLXI_10" orien="R0" />
        <branch name="XLXN_17">
            <wire x2="592" y1="832" y2="832" x1="560" />
        </branch>
        <instance x="336" y="864" name="XLXI_11" orien="R0" />
        <branch name="C">
            <wire x2="592" y1="592" y2="592" x1="128" />
        </branch>
        <branch name="B">
            <wire x2="336" y1="832" y2="832" x1="128" />
        </branch>
        <branch name="A">
            <wire x2="208" y1="528" y2="528" x1="128" />
            <wire x2="592" y1="528" y2="528" x1="208" />
            <wire x2="208" y1="528" y2="768" x1="208" />
            <wire x2="592" y1="768" y2="768" x1="208" />
        </branch>
        <iomarker fontsize="28" x="128" y="528" name="A" orien="R180" />
        <iomarker fontsize="28" x="128" y="592" name="C" orien="R180" />
        <iomarker fontsize="28" x="128" y="832" name="B" orien="R180" />
        <instance x="1072" y="752" name="XLXI_12" orien="R0" />
        <branch name="XLXN_22">
            <wire x2="960" y1="560" y2="560" x1="848" />
            <wire x2="960" y1="560" y2="624" x1="960" />
            <wire x2="1072" y1="624" y2="624" x1="960" />
        </branch>
        <branch name="XLXN_23">
            <wire x2="960" y1="800" y2="800" x1="848" />
            <wire x2="960" y1="688" y2="800" x1="960" />
            <wire x2="1072" y1="688" y2="688" x1="960" />
        </branch>
        <branch name="Z">
            <wire x2="1360" y1="656" y2="656" x1="1328" />
        </branch>
        <iomarker fontsize="28" x="1360" y="656" name="Z" orien="R0" />
    </sheet>
</drawing>