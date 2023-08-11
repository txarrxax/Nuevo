<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan3" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="A" />
        <signal name="B" />
        <signal name="C" />
        <signal name="D" />
        <signal name="Z" />
        <signal name="XLXN_6" />
        <signal name="XLXN_7" />
        <signal name="XLXN_8" />
        <signal name="XLXN_9" />
        <signal name="XLXN_10" />
        <signal name="XLXN_11" />
        <signal name="XLXN_12" />
        <port polarity="Input" name="A" />
        <port polarity="Input" name="B" />
        <port polarity="Input" name="C" />
        <port polarity="Input" name="D" />
        <port polarity="Output" name="Z" />
        <blockdef name="d4_16e">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <rect width="256" x="64" y="-1152" height="1088" />
            <line x2="320" y1="-1088" y2="-1088" x1="384" />
            <line x2="320" y1="-1024" y2="-1024" x1="384" />
            <line x2="320" y1="-960" y2="-960" x1="384" />
            <line x2="320" y1="-896" y2="-896" x1="384" />
            <line x2="320" y1="-832" y2="-832" x1="384" />
            <line x2="320" y1="-768" y2="-768" x1="384" />
            <line x2="320" y1="-704" y2="-704" x1="384" />
            <line x2="320" y1="-640" y2="-640" x1="384" />
            <line x2="320" y1="-576" y2="-576" x1="384" />
            <line x2="320" y1="-512" y2="-512" x1="384" />
            <line x2="320" y1="-448" y2="-448" x1="384" />
            <line x2="320" y1="-384" y2="-384" x1="384" />
            <line x2="320" y1="-320" y2="-320" x1="384" />
            <line x2="320" y1="-256" y2="-256" x1="384" />
            <line x2="320" y1="-192" y2="-192" x1="384" />
            <line x2="320" y1="-128" y2="-128" x1="384" />
            <line x2="64" y1="-896" y2="-896" x1="0" />
            <line x2="64" y1="-960" y2="-960" x1="0" />
            <line x2="64" y1="-1024" y2="-1024" x1="0" />
            <line x2="64" y1="-1088" y2="-1088" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
        </blockdef>
        <blockdef name="nor6">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="48" y1="-176" y2="-176" x1="52" />
            <line x2="68" y1="-176" y2="-176" x1="52" />
            <line x2="68" y1="-272" y2="-272" x1="48" />
            <line x2="64" y1="-256" y2="-256" x1="32" />
            <line x2="64" y1="-272" y2="-272" x1="128" />
            <line x2="48" y1="-64" y2="-176" x1="48" />
            <line x2="64" y1="-192" y2="-192" x1="0" />
            <line x2="48" y1="-128" y2="-128" x1="0" />
            <line x2="48" y1="-64" y2="-64" x1="0" />
            <line x2="228" y1="-224" y2="-224" x1="256" />
            <circle r="10" cx="218" cy="-226" />
            <line x2="48" y1="-384" y2="-384" x1="0" />
            <line x2="48" y1="-320" y2="-320" x1="0" />
            <line x2="64" y1="-256" y2="-256" x1="0" />
            <line x2="48" y1="-272" y2="-384" x1="48" />
            <arc ex="208" ey="-224" sx="128" sy="-176" r="88" cx="132" cy="-264" />
            <line x2="64" y1="-176" y2="-176" x1="128" />
            <arc ex="128" ey="-272" sx="208" sy="-224" r="88" cx="132" cy="-184" />
            <arc ex="48" ey="-272" sx="48" sy="-176" r="56" cx="16" cy="-224" />
        </blockdef>
        <blockdef name="vcc">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-64" x1="64" />
            <line x2="64" y1="0" y2="-32" x1="64" />
            <line x2="32" y1="-64" y2="-64" x1="96" />
        </blockdef>
        <block symbolname="d4_16e" name="XLXI_1">
            <blockpin signalname="D" name="A0" />
            <blockpin signalname="C" name="A1" />
            <blockpin signalname="B" name="A2" />
            <blockpin signalname="A" name="A3" />
            <blockpin signalname="XLXN_12" name="E" />
            <blockpin signalname="XLXN_6" name="D0" />
            <blockpin signalname="XLXN_7" name="D1" />
            <blockpin name="D10" />
            <blockpin signalname="XLXN_10" name="D11" />
            <blockpin name="D12" />
            <blockpin name="D13" />
            <blockpin name="D14" />
            <blockpin signalname="XLXN_11" name="D15" />
            <blockpin name="D2" />
            <blockpin signalname="XLXN_8" name="D3" />
            <blockpin name="D4" />
            <blockpin name="D5" />
            <blockpin name="D6" />
            <blockpin name="D7" />
            <blockpin name="D8" />
            <blockpin signalname="XLXN_9" name="D9" />
        </block>
        <block symbolname="nor6" name="XLXI_2">
            <blockpin signalname="XLXN_11" name="I0" />
            <blockpin signalname="XLXN_10" name="I1" />
            <blockpin signalname="XLXN_9" name="I2" />
            <blockpin signalname="XLXN_8" name="I3" />
            <blockpin signalname="XLXN_7" name="I4" />
            <blockpin signalname="XLXN_6" name="I5" />
            <blockpin signalname="Z" name="O" />
        </block>
        <block symbolname="vcc" name="XLXI_3">
            <blockpin signalname="XLXN_12" name="P" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="960" y="1680" name="XLXI_1" orien="R0" />
        <branch name="A">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="944" y="784" type="branch" />
            <wire x2="944" y1="784" y2="784" x1="928" />
            <wire x2="960" y1="784" y2="784" x1="944" />
        </branch>
        <iomarker fontsize="28" x="928" y="784" name="A" orien="R180" />
        <branch name="B">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="944" y="720" type="branch" />
            <wire x2="944" y1="720" y2="720" x1="928" />
            <wire x2="960" y1="720" y2="720" x1="944" />
        </branch>
        <iomarker fontsize="28" x="928" y="720" name="B" orien="R180" />
        <branch name="C">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="944" y="656" type="branch" />
            <wire x2="944" y1="656" y2="656" x1="928" />
            <wire x2="960" y1="656" y2="656" x1="944" />
        </branch>
        <iomarker fontsize="28" x="928" y="656" name="C" orien="R180" />
        <branch name="D">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="944" y="592" type="branch" />
            <wire x2="944" y1="592" y2="592" x1="928" />
            <wire x2="960" y1="592" y2="592" x1="944" />
        </branch>
        <iomarker fontsize="28" x="928" y="592" name="D" orien="R180" />
        <instance x="1728" y="1296" name="XLXI_2" orien="R0" />
        <branch name="Z">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2000" y="1072" type="branch" />
            <wire x2="2000" y1="1072" y2="1072" x1="1984" />
            <wire x2="2016" y1="1072" y2="1072" x1="2000" />
        </branch>
        <iomarker fontsize="28" x="2016" y="1072" name="Z" orien="R0" />
        <branch name="XLXN_6">
            <wire x2="1728" y1="592" y2="592" x1="1344" />
            <wire x2="1728" y1="592" y2="912" x1="1728" />
        </branch>
        <branch name="XLXN_7">
            <wire x2="1536" y1="656" y2="656" x1="1344" />
            <wire x2="1536" y1="656" y2="976" x1="1536" />
            <wire x2="1728" y1="976" y2="976" x1="1536" />
        </branch>
        <branch name="XLXN_8">
            <wire x2="1520" y1="784" y2="784" x1="1344" />
            <wire x2="1520" y1="784" y2="1040" x1="1520" />
            <wire x2="1728" y1="1040" y2="1040" x1="1520" />
        </branch>
        <branch name="XLXN_9">
            <wire x2="1536" y1="1168" y2="1168" x1="1344" />
            <wire x2="1536" y1="1104" y2="1168" x1="1536" />
            <wire x2="1728" y1="1104" y2="1104" x1="1536" />
        </branch>
        <branch name="XLXN_10">
            <wire x2="1360" y1="1296" y2="1296" x1="1344" />
            <wire x2="1552" y1="1296" y2="1296" x1="1360" />
            <wire x2="1552" y1="1168" y2="1296" x1="1552" />
            <wire x2="1728" y1="1168" y2="1168" x1="1552" />
        </branch>
        <branch name="XLXN_11">
            <wire x2="1728" y1="1552" y2="1552" x1="1344" />
            <wire x2="1728" y1="1232" y2="1552" x1="1728" />
        </branch>
        <branch name="XLXN_12">
            <wire x2="960" y1="1552" y2="1552" x1="928" />
        </branch>
        <instance x="928" y="1616" name="XLXI_3" orien="R270" />
    </sheet>
</drawing>