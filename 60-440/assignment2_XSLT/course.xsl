<?xml version="1.0" encoding="utf-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
<xsl:template match="courses">
  <html>
    <head>
    <script>
      function addDisplay(details) {
        document.write(details);
      }
    </script>
    </head>
    <body>
      <table border="1">
      <tr>
        <td>
          <b>Course No.</b>
        </td>
        <td>
          <b>Course Title</b>
        </td>
        <td>
          <b>Prof</b>
        </td>
        <td>
          <b>Year</b>
        </td>
        <td>
          <b>Days</b>
        </td>
        <td>
          <b>Time</b>
        </td>
        <td>
          <b>Location</b>
        </td>
      </tr>
        <xsl:for-each select="course[@acad_year >= 2003]">
          <tr>
            <td>
              <xsl:for-each select="course_num">
                <xsl:apply-templates/>
                <xsl:if test="position()!=last()"> , </xsl:if>
              </xsl:for-each>
            </td>
            <td>
              <a>
                <xsl:attribute name="href">javascript:addDisplay('<xsl:value-of select="description"/>');</xsl:attribute>
                <xsl:apply-templates select="title"/>
              </a>
            </td>
            <td>
              <xsl:for-each select="course_head/person">
                <xsl:apply-templates select="person_name"/>
                <xsl:if test="position()!=last()"> , </xsl:if>
              </xsl:for-each>
            </td>
            <td>
              <xsl:value-of select="@acad_year"/>
            </td>
            <td>
              <xsl:apply-templates select="meeting/meeting_days"/>
            </td>
            <td>
              <xsl:apply-templates select="meeting/meeting_begin"/>
              -
              <xsl:apply-templates select="meeting/meeting_end"/>
            </td>
            <td>
              <xsl:apply-templates select="meeting/location"/>
            </td>
          </tr>
        </xsl:for-each>
      </table>
    </body>
  </html>
</xsl:template>
</xsl:stylesheet>
