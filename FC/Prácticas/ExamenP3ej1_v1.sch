<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan3" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="INIT" />
        <signal name="CLK" />
        <signal name="XLXN_3" />
        <signal name="XLXN_4" />
        <signal name="Q0" />
        <signal name="Q1" />
        <signal name="XLXN_9" />
        <signal name="Q2" />
        <signal name="Q3" />
        <port polarity="Input" name="INIT" />
        <port polarity="Input" name="CLK" />
        <port polarity="Output" name="Q0" />
        <port polarity="Output" name="Q1" />
        <port polarity="Output" name="Q2" />
        <port polarity="Output" name="Q3" />
        <blockdef name="cb4cled">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <rect width="256" x="64" y="-704" height="640" />
            <line x2="64" y1="-256" y2="-256" x1="0" />
            <line x2="320" y1="-192" y2="-192" x1="384" />
            <line x2="320" y1="-448" y2="-448" x1="384" />
            <line x2="320" y1="-512" y2="-512" x1="384" />
            <line x2="320" y1="-576" y2="-576" x1="384" />
            <line x2="320" y1="-640" y2="-640" x1="384" />
            <line x2="64" y1="-448" y2="-448" x1="0" />
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="64" y1="-128" y2="-144" x1="80" />
            <line x2="80" y1="-112" y2="-128" x1="64" />
            <line x2="64" y1="-32" y2="-32" x1="192" />
            <line x2="192" y1="-64" y2="-32" x1="192" />
            <line x2="64" y1="-512" y2="-512" x1="0" />
            <line x2="64" y1="-576" y2="-576" x1="0" />
            <line x2="64" y1="-640" y2="-640" x1="0" />
            <line x2="64" y1="-192" y2="-192" x1="0" />
            <line x2="64" y1="-320" y2="-320" x1="0" />
            <line x2="320" y1="-128" y2="-128" x1="384" />
        </blockdef>
        <blockdef name="vcc">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-64" x1="64" />
            <line x2="64" y1="0" y2="-32" x1="64" />
            <line x2="32" y1="-64" y2="-64" x1="96" />
        </blockdef>
        <blockdef name="gnd">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-96" x1="64" />
            <line x2="52" y1="-48" y2="-48" x1="76" />
            <line x2="60" y1="-32" y2="-32" x1="68" />
            <line x2="40" y1="-64" y2="-64" x1="88" />
            <line x2="64" y1="-64" y2="-80" x1="64" />
            <line x2="64" y1="-128" y2="-96" x1="64" />
        </blockdef>
        <blockdef name="and4b1">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="40" y1="-64" y2="-64" x1="0" />
            <circle r="12" cx="52" cy="-64" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="64" y1="-192" y2="-192" x1="0" />
            <line x2="64" y1="-256" y2="-256" x1="0" />
            <line x2="192" y1="-160" y2="-160" x1="256" />
            <line x2="64" y1="-64" y2="-256" x1="64" />
            <line x2="64" y1="-112" y2="-112" x1="144" />
            <arc ex="144" ey="-208" sx="144" sy="-112" r="48" cx="144" cy="-160" />
            <line x2="144" y1="-208" y2="-208" x1="64" />
        </blockdef>
        <block symbolname="cb4cled" name="XLXI_1">
            <blockpin signalname="CLK" name="C" />
            <blockpin signalname="XLXN_3" name="CE" />
            <blockpin signalname="INIT" name="CLR" />
            <blockpin signalname="XLXN_3" name="D0" />
            <blockpin signalname="XLXN_3" name="D1" />
            <blockpin signalname="XLXN_3" name="D2" />
            <blockpin signalname="XLXN_3" name="D3" />
            <blockpin signalname="XLXN_9" name="L" />
            <blockpin signalname="XLXN_4" name="UP" />
            <blockpin name="CEO" />
            <blockpin signalname="Q3" name="Q0" />
            <blockpin signalname="Q2" name="Q1" />
            <blockpin signalname="Q1" name="Q2" />
            <blockpin signalname="Q0" name="Q3" />
            <blockpin name="TC" />
        </block>
        <block symbolname="vcc" name="XLXI_3">
            <blockpin signalname="XLXN_3" name="P" />
        </block>
        <block symbolname="gnd" name="XLXI_4">
            <blockpin signalname="XLXN_4" name="G" />
        </block>
        <block symbolname="and4b1" name="XLXI_10">
            <blockpin signalname="Q0" name="I0" />
            <blockpin signalname="Q1" name="I1" />
            <blockpin signalname="Q2" name="I2" />
            <blockpin signalname="Q3" name="I3" />
            <blockpin signalname="XLXN_9" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="656" y="1584" name="XLXI_1" orien="R0" />
        <branch name="INIT">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="640" y="1552" type="branch" />
            <wire x2="640" y1="1552" y2="1552" x1="624" />
            <wire x2="656" y1="1552" y2="1552" x1="640" />
        </branch>
        <iomarker fontsize="28" x="624" y="1552" name="INIT" orien="R180" />
        <branch name="CLK">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="640" y="1456" type="branch" />
            <wire x2="640" y1="1456" y2="1456" x1="624" />
            <wire x2="656" y1="1456" y2="1456" x1="640" />
        </branch>
        <iomarker fontsize="28" x="624" y="1456" name="CLK" orien="R180" />
        <instance x="128" y="864" name="XLXI_3" orien="R0" />
        <instance x="416" y="736" name="XLXI_4" orien="R180" />
        <branch name="XLXN_3">
            <wire x2="192" y1="864" y2="944" x1="192" />
            <wire x2="656" y1="944" y2="944" x1="192" />
            <wire x2="192" y1="944" y2="1008" x1="192" />
            <wire x2="656" y1="1008" y2="1008" x1="192" />
            <wire x2="192" y1="1008" y2="1072" x1="192" />
            <wire x2="656" y1="1072" y2="1072" x1="192" />
            <wire x2="192" y1="1072" y2="1136" x1="192" />
            <wire x2="192" y1="1136" y2="1392" x1="192" />
            <wire x2="656" y1="1392" y2="1392" x1="192" />
            <wire x2="656" y1="1136" y2="1136" x1="192" />
        </branch>
        <branch name="XLXN_4">
            <wire x2="352" y1="864" y2="1264" x1="352" />
            <wire x2="656" y1="1264" y2="1264" x1="352" />
        </branch>
        <branch name="Q2">
            <attrtext style="alignment:SOFT-TVCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1168" y="1264" type="branch" />
            <wire x2="1168" y1="1008" y2="1008" x1="1040" />
            <wire x2="1168" y1="1008" y2="1264" x1="1168" />
            <wire x2="1168" y1="1264" y2="1280" x1="1168" />
            <wire x2="1440" y1="1008" y2="1008" x1="1168" />
        </branch>
        <branch name="Q1">
            <attrtext style="alignment:SOFT-TVCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1216" y="1264" type="branch" />
            <wire x2="1216" y1="1072" y2="1072" x1="1040" />
            <wire x2="1216" y1="1072" y2="1264" x1="1216" />
            <wire x2="1216" y1="1264" y2="1280" x1="1216" />
            <wire x2="1440" y1="1072" y2="1072" x1="1216" />
        </branch>
        <branch name="Q0">
            <attrtext style="alignment:SOFT-TVCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1264" y="1264" type="branch" />
            <wire x2="1264" y1="1136" y2="1136" x1="1040" />
            <wire x2="1264" y1="1136" y2="1264" x1="1264" />
            <wire x2="1264" y1="1264" y2="1280" x1="1264" />
            <wire x2="1440" y1="1136" y2="1136" x1="1264" />
        </branch>
        <branch name="XLXN_9">
            <wire x2="640" y1="816" y2="1328" x1="640" />
            <wire x2="656" y1="1328" y2="1328" x1="640" />
            <wire x2="1760" y1="816" y2="816" x1="640" />
            <wire x2="1760" y1="816" y2="1040" x1="1760" />
            <wire x2="1760" y1="1040" y2="1040" x1="1696" />
        </branch>
        <iomarker fontsize="28" x="1120" y="1280" name="Q3" orien="R90" />
        <iomarker fontsize="28" x="1168" y="1280" name="Q2" orien="R90" />
        <iomarker fontsize="28" x="1216" y="1280" name="Q1" orien="R90" />
        <iomarker fontsize="28" x="1264" y="1280" name="Q0" orien="R90" />
        <branch name="Q3">
            <attrtext style="alignment:SOFT-TVCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1120" y="1264" type="branch" />
            <wire x2="1120" y1="944" y2="944" x1="1040" />
            <wire x2="1120" y1="944" y2="1264" x1="1120" />
            <wire x2="1120" y1="1264" y2="1280" x1="1120" />
            <wire x2="1440" y1="944" y2="944" x1="1120" />
        </branch>
        <instance x="1440" y="1200" name="XLXI_10" orien="R0" />
    </sheet>
</drawing>