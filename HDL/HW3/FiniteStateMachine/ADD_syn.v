/////////////////////////////////////////////////////////////
// Created by: Synopsys DC Expert(TM) in wire load mode
// Version   : K-2015.06-SP1
// Date      : Mon Apr 16 19:57:06 2018
/////////////////////////////////////////////////////////////


module ADD ( clk, rst, start, data, en, addr, fin, result );
  input [2:0] data;
  output [2:0] addr;
  output [2:0] result;
  input clk, rst, start;
  output en, fin;
  wire   state, N16, n8, n10, n12, n13, n15, n16, n17, n18, n19, n20, n21, n22,
         n23, n24, n26, n27, n28, n29, n30, n31, n32, n34, n35, n36, n37, n39,
         n40, n41, n42, n43, n45, n46, n47, n48, n49, n50, n51, n52, n53, n54,
         n55, n56, n57, n58, n59;
  wire   [2:0] next_num;
  assign en = 1'b1;
  assign fin = N16;

  DFFSX1 \num_reg[0]  ( .D(next_num[0]), .CK(clk), .SN(n49), .Q(addr[0]), .QN(
        n40) );
  DFFSX1 \num_reg[1]  ( .D(next_num[1]), .CK(clk), .SN(n49), .Q(addr[1]), .QN(
        n43) );
  DFFSX1 \num_reg[2]  ( .D(next_num[2]), .CK(clk), .SN(n49), .Q(addr[2]) );
  DFFRX1 state_reg ( .D(n56), .CK(clk), .RN(n49), .Q(state), .QN(n57) );
  DFFRX1 \leng_reg[2]  ( .D(n55), .CK(clk), .RN(n49), .QN(n48) );
  DFFRX1 \leng_reg[0]  ( .D(n54), .CK(clk), .RN(n49), .QN(n47) );
  DFFRX1 \leng_reg[1]  ( .D(n53), .CK(clk), .RN(n49), .Q(n59), .QN(n46) );
  DFFRX1 \ans_reg[0]  ( .D(n52), .CK(clk), .RN(n49), .QN(n45) );
  DFFRX1 \ans_reg[1]  ( .D(n51), .CK(clk), .RN(n49), .Q(n58), .QN(n42) );
  DFFRX1 \ans_reg[2]  ( .D(n50), .CK(clk), .RN(n49), .QN(n41) );
  CLKINVX1 U3 ( .A(rst), .Y(n49) );
  NOR2X1 U4 ( .A(n41), .B(n8), .Y(result[2]) );
  NOR2X1 U5 ( .A(n42), .B(n8), .Y(result[1]) );
  NOR2X1 U6 ( .A(n45), .B(n8), .Y(result[0]) );
  OAI21XL U7 ( .A0(n57), .A1(n10), .B0(n56), .Y(next_num[2]) );
  XNOR2X1 U8 ( .A(addr[2]), .B(n12), .Y(n10) );
  NOR2X1 U9 ( .A(n43), .B(n40), .Y(n12) );
  OAI21XL U10 ( .A0(n13), .A1(n57), .B0(n56), .Y(next_num[1]) );
  XNOR2X1 U11 ( .A(n43), .B(n40), .Y(n13) );
  OAI21XL U12 ( .A0(addr[0]), .A1(n57), .B0(n56), .Y(next_num[0]) );
  NAND2BX1 U13 ( .AN(start), .B(n57), .Y(n56) );
  OAI2BB2XL U14 ( .B0(n48), .B1(n15), .A0N(n15), .A1N(data[2]), .Y(n55) );
  OAI22XL U15 ( .A0(n46), .A1(n15), .B0(n16), .B1(n17), .Y(n53) );
  OAI2BB2XL U16 ( .B0(n47), .B1(n15), .A0N(n15), .A1N(data[0]), .Y(n54) );
  CLKINVX1 U17 ( .A(n16), .Y(n15) );
  NAND2X1 U18 ( .A(start), .B(n57), .Y(n16) );
  XOR2X1 U20 ( .A(n18), .B(n41), .Y(n50) );
  NAND2X1 U21 ( .A(n19), .B(n20), .Y(n18) );
  XOR2X1 U22 ( .A(n21), .B(data[2]), .Y(n19) );
  NAND2BX1 U23 ( .AN(n22), .B(n23), .Y(n21) );
  OAI21XL U24 ( .A0(n24), .A1(data[1]), .B0(n58), .Y(n23) );
  OAI32X1 U25 ( .A0(n58), .A1(n26), .A2(n27), .B0(n42), .B1(n28), .Y(n51) );
  AOI211X1 U26 ( .A0(n29), .A1(n17), .B0(n27), .C0(n22), .Y(n28) );
  NOR2X1 U27 ( .A(n29), .B(n17), .Y(n22) );
  CLKINVX1 U28 ( .A(data[1]), .Y(n17) );
  CLKINVX1 U29 ( .A(n24), .Y(n29) );
  XNOR2X1 U30 ( .A(n24), .B(data[1]), .Y(n26) );
  NOR2BX1 U31 ( .AN(data[0]), .B(n45), .Y(n24) );
  XOR2X1 U33 ( .A(n30), .B(n45), .Y(n52) );
  NAND2X1 U34 ( .A(n20), .B(data[0]), .Y(n30) );
  CLKINVX1 U35 ( .A(n27), .Y(n20) );
  NAND2X1 U36 ( .A(state), .B(n31), .Y(n27) );
  CLKINVX1 U37 ( .A(n8), .Y(N16) );
  NAND3BX1 U38 ( .AN(n31), .B(start), .C(n32), .Y(n8) );
  AOI221XL U39 ( .A0(n46), .A1(addr[1]), .B0(n47), .B1(addr[0]), .C0(n34), .Y(
        n32) );
  CLKINVX1 U40 ( .A(n35), .Y(n34) );
  OAI21XL U41 ( .A0(n48), .A1(addr[2]), .B0(n36), .Y(n31) );
  OAI211X1 U42 ( .A0(n37), .A1(n59), .B0(n35), .C0(n39), .Y(n36) );
  OAI21XL U43 ( .A0(n47), .A1(addr[0]), .B0(addr[1]), .Y(n39) );
  NAND2X1 U44 ( .A(n48), .B(addr[2]), .Y(n35) );
  NOR3X1 U46 ( .A(addr[0]), .B(n47), .C(addr[1]), .Y(n37) );
endmodule

