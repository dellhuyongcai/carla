/*
    Project includes
*/
#include "TrafficSignalsParser.h"

/*
    Lib includes
*/

/*
    STD/C++ includes
*/

///////////////////////////////////////////////////////////////////////////////

void opendrive::parser::TrafficSignalsParser::Parse(const pugi::xml_node & xmlNode, std::vector<opendrive::types::TrafficSignalInformation> & out_traffic_signals)
{
    for (pugi::xml_node signal = xmlNode.child("signal"); signal; signal = signal.next_sibling("signal"))
    {
        opendrive::types::TrafficSignalInformation trafficSignalInformation;

        trafficSignalInformation.id = std::atoi(signal.attribute("id").value());

        trafficSignalInformation.start_position = std::stod(signal.attribute("s").value());
        trafficSignalInformation.track_position = std::stod(signal.attribute("t").value());

        trafficSignalInformation.zoffset = std::stod(signal.attribute("zOffset").value());
        trafficSignalInformation.value = std::stod(signal.attribute("value").value());

        trafficSignalInformation.name = signal.attribute("name").value();
        trafficSignalInformation.dynamic = signal.attribute("dynamic").value();
        trafficSignalInformation.orientation = signal.attribute("orientation").value();

        trafficSignalInformation.type = signal.attribute("type").value();
        trafficSignalInformation.subtype = signal.attribute("subtype").value();
        trafficSignalInformation.country = signal.attribute("country").value();

        out_traffic_signals.push_back(trafficSignalInformation);
    }
}